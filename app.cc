#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"

#include "phys_cc1350.h"
#include "plug_null.h"

#define MAX_RECORDS 40
#define	MAX_PACKET_LENGTH 250
#define RECORD_LENGTH 20
#define MAX_NEIGHBOURS 26

typedef enum {DISCOVERY_REQUEST, DISCOVERY_RESPONSE, CREATE_RECORD, DELETE_RECORD, RETRIEVE_RECORD, RESPONSE, IDLE = -1} protocol;

typedef struct {
    short senderGroupId;
    char messageType;
    char requestNumber;
    char senderId;
    char destinationId;
    char messageRecord[RECORD_LENGTH];
    char recordIndex;
    char status;
} message;

typedef struct {
    time_t timeStamp;
    char ownerId;
    char recordMessage[RECORD_LENGTH];
} record;

record database[MAX_RECORDS];

char neighbours[MAX_NEIGHBOURS];

char nodeId;
short groupId;

int recordCount;
int neighbourCount;

char currentRequestNumber;

protocol currentProtocol;

message * messagePtr;

int sfd = -1;

/**
 * Assembles the message in the message struct into a character array
 * 
 * Parameters:
 *      messagePtr: a pointer to a message struct
 * 
 * Return:
 *      Returns a character array that holds the required message to be sent
*/
char * assembleMessage(message * messagePtr) {
    char * p;

    switch(messagePtr->messageType) 
    {
    case DISCOVERY_REQUEST:
    case DISCOVERY_RESPONSE:
        p = (char*)umalloc(6);
        break;

    case RETRIEVE_RECORD:
    case DELETE_RECORD:
        p = (char*)umalloc(8);

        p[6] = messagePtr->recordIndex;
        p[7] = 0x00;
        break;
    
    case CREATE_RECORD:
        p = (char*)umalloc(26);
        strcpy(p + 6, messagePtr->messageRecord);
        break;
    
    case RESPONSE:
        p = (char*)umalloc(28);
        p[6] = messagePtr->status;
        p[7] = 0x00;
        strcpy(p + 8, messagePtr->messageRecord);
        break;
    } 

    p[0] = messagePtr->senderGroupId;
    p[2] = messagePtr->messageType;
    p[3] = messagePtr->requestNumber;
    p[4] = messagePtr->senderId;
    p[5] = messagePtr->destinationId;

    return p;
}

/**
 * Determines the size of the packet to send based on the message type
 * 
 * Parameter:
 *      messageType: a character representing the message type
 * 
 * Return:
 *      an integer of how big the packet needs to be
*/
int getPacketSize(char messageType) {
    int size = 0;
    
    switch(messageType) 
    {
    case DISCOVERY_REQUEST:
    case DISCOVERY_RESPONSE:
        size = 6;
        break;

    case RETRIEVE_RECORD:
    case DELETE_RECORD:
        size = 8;
        break;
    
    case CREATE_RECORD:
        size = 26;
        break;
    
    case RESPONSE:
        size = 28;
        break;
    }

    return size + 4; // add four bytes for the two bytes before and after the payload
}

/**
 * State machine for handling transmitting messages
*/
fsm transmitter (message * messagePtr) {
    state Transmit_Message:

        char * assembledMessage = assembleMessage(messagePtr);

        address spkt;

        // populate packet pointer
        spkt = tcv_wnp (Transmit_Message, sfd,  getPacketSize(messagePtr->messageType));
        spkt [0] = 0;
        char * p = (char*)(spkt + 1); // skip first 2 bytes
        strcpy(p, assembledMessage);

        tcv_endp (spkt);

    state Confirm_Transmission:
        finish;
}

/**
 * Generates a random number
 * 
 *  Return:
 *      returns a random 1 byte number
*/
char randomNumber() {
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   return (char)rand();
}

void resetNeighbours(){
    for (int i = 0; i < MAX_NEIGHBOURS; i ++) {
        neighbours[i] = 0;
    }
}

/**
 * State machine for sending a discovery request
*/
fsm find {
    int sendCount;
    int i;

    state Initialize:
        i = 0;
        sendCount = 0;
        currentRequestNumber = randomNumber();

        messagePtr -> senderGroupId = groupId;
        messagePtr -> messageType = 0;
        messagePtr -> requestNumber = currentRequestNumber;
        messagePtr -> senderId = nodeId;
        messagePtr -> destinationId = 0;

    state Send_Discovery_Request:
        if(sendCount == 2) {
            proceed Display_Neighbours;
        }

        call transmitter(messagePtr, Wait);
        sendCount++;

    state Wait:
        delay(3*1024, Send_Discovery_Request);
        
    state Display_Neighbours:
        ser_outf(Display_Neighbours, "Neighbours:");
    
    state Display_Neighbour:
        if (neighbours[i] == 1) {
            ser_outf(Display_Neighbour, " %d", i);
        }

        i++;

        if(i < MAX_NEIGHBOURS) {
            proceed Display_Neighbour;
        }

        finish;
}

/**
 * Ensures node ID is valid
 * 
 *  Parameters:
 *      node: The node ID being checked
 * 
 *  Return:
 *      returns whether the node is valid
*/
Boolean isValidNodeId(byte node) {
    if (node < 1 || node > 25) {
        return NO;
    }

    return YES;
}

fsm root {

    char * menu = "(G)roup ID\r\n"
"(N)ew device ID\r\n"
"(F)ind neighbors\r\n"
"(C)reate record on neighbor\r\n"
"(D)elete record on neighbor\r\n"
"(R)etrieve record from neighbor\r\n"
"(S)how local records\r\n"
"R(e)set local storage\r\n\r\n"
"Selection: ";

    char receiverId;

    state Initialize:
        recordCount = 0;

        nodeId = 1;
        groupId = 1;

        messagePtr = (message *) umalloc(sizeof(message));

        // Set up cc1350 board
        phys_cc1350(0, MAX_PACKET_LENGTH);

        // Load null plug in
        tcv_plug(0, &plug_null);

        // Open the session
        sfd = tcv_open(WNONE, 0, 0);
		tcv_control(sfd, PHYSOPT_ON, NULL);

        // Ensure session opened properly
		if (sfd < 0) {
			diag("Cannot open tcv interface");
			halt();
		}

    state Menu_Header:
        currentProtocol = IDLE;
        ser_outf(Menu_Header, "\r\nGroup %d Device #%d (%d/%d records)\r\n", groupId, nodeId, recordCount, MAX_RECORDS);
    
    state Options:
        ser_outf(Options, menu);

    state Get_Choice:
        char choice;

        ser_inf(Get_Choice, "%c", &choice);

        switch (choice)
        {
        case 'g':
        case 'G':
            proceed Set_Group_ID;
            break;
        
        case 'n':
        case 'N':
            proceed Set_Node_ID;
            break;
        
        case 'f':
        case 'F':
            proceed Find_Neighbours;
            break;
        
        case 'c':
        case 'C':
            proceed Create_Record;
            break;

        case 'd':
        case 'D':
            proceed Delete_Record;
            break;

        case 'r':
        case 'R':
            proceed Retrieve_Record;
            break;
        
        case 's':
        case 'S':
            diag("Show Local Records");
            break;
        
        case 'e':
        case 'E':
            diag("Reset Local Storage");
            break;

        }
        
        proceed Menu_Header;

// - - - - - - - - - - - Set Group ID - - - - - - - - - - - - //
    state Set_Group_ID:
        ser_outf(Set_Group_ID, "New Group ID: ");
    state Get_Group_ID:
        ser_inf(Get_Group_ID, "%d", &groupId);

        proceed Menu_Header;

// - - - - - - - - - - - Set Node ID - - - - - - - - - - - - //    
    state Set_Node_ID:
        ser_outf(Set_Node_ID, "New node ID (1-25):");
    
    state Get_Node_ID:
        ser_inf(Get_Node_ID, "%d", &nodeId);

        if (!isValidNodeId(nodeId)) {
            proceed Set_Node_ID;
        }

        proceed Menu_Header;

// - - - - - - - - - - - - Find Neighbour - - - - - - - - - - - - - //
    state Find_Neighbours:
        call find(Menu_Header);
        // currentProtocol = DISCOVERY_REQUEST;
        // receiverId = 0;
        // proceed Transmit_Message;

// - - - - - - - - - - - - Create Recrods - - - - - - - - - - - - - //    
    state Create_Record:
        currentProtocol = CREATE_RECORD;
        ser_outf(Create_Record, "Receiver node ID (1-25):");
    
    state Get_Receiver_Node:
        ser_inf(Get_Receiver_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId)) {
            proceed Create_Record;
        }

    state Get_Message:
        ser_in(Get_Message, messagePtr->messageRecord, RECORD_LENGTH);

        if(strlen(messagePtr->messageRecord) >= RECORD_LENGTH) {
            // ensures that the last byte in the payload message is a null character
            messagePtr->messageRecord[RECORD_LENGTH - 1] = '/0';
        }

        proceed Transmit_Message;

// - - - - - - - - Deleting and Retreiving Records - - - - - - - - //

    state Delete_Record:
        currentProtocol = DELETE_RECORD;
        ser_outf(Retrieve_Record, "Delete Record from Neighbour:\n\r");
        proceed Get_Receiving_Node;

    state Retrieve_Record:
        currentProtocol = RETRIEVE_RECORD;
        ser_outf(Retrieve_Record, "Retrieve Record from Neighbour:\n\r");

    state Prompt_Recieving_Node:
        ser_outf(Prompt_Recieving_Node, "Neighbour node ID (1-25):");
    
    state Get_Receiving_Node:
        ser_inf(Get_Receiving_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId)) {
            proceed Prompt_Recieving_Node;
        }
    
    state Prompt_Record_Index:
        ser_outf(Prompt_Record_Index, "Record index:");
    
    state Get_Record_Index:
        char desiredRecordIndex = -1;
        ser_inf(Get_Record_Index, "%d", &desiredRecordIndex);
        messagePtr->recordIndex = desiredRecordIndex;

        proceed Transmit_Message;

// - - - - - - Assemble Common Parts and Send Message - - - - - - - //
    state Transmit_Message:
        messagePtr -> senderGroupId = groupId;
        messagePtr -> messageType = currentProtocol;
        messagePtr -> requestNumber = randomNumber();
        messagePtr -> senderId = nodeId;
        messagePtr -> destinationId = receiverId;

        call transmitter(messagePtr, Menu_Header);
}