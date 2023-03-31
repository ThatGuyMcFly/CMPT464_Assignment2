#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"

#include "phys_cc1350.h"
#include "plug_null.h"

#include "time.h"

#define MAX_RECORDS 40
#define	MAX_PACKET_LENGTH 250
#define RECORD_LENGTH 20
#define MAX_NEIGHBOURS 26
#define SECOND 1024

typedef enum {DISCOVERY_REQUEST, DISCOVERY_RESPONSE, CREATE_RECORD, DELETE_RECORD, RETRIEVE_RECORD, RESPONSE} protocol;

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

typedef struct {
    char messageSize;
    char * messageContent;
} messageDetails;

record database[MAX_RECORDS];

char neighbours[MAX_NEIGHBOURS];

char nodeId;
short groupId;

int recordCount;
int neighbourCount;

char currentRequestNumber;

protocol currentProtocol;

int sfd = -1;
void printByteArray(char* pointer, int length) {
    for (int i = 0; i < length; i++) {
        diag("%x", pointer[i]);
    }
}

/**
 * Creates a struct that holds the message content and size of the message
 * 
 * Parameters:
 *      messagePtr: a pointer to a message struct
 * 
 * Return:
 *      a struct with the message contents and size
*/
messageDetails getMessageDetials(message * messagePtr) {
    messageDetails details;

    char * p;
    char size;
    switch(messagePtr->messageType) 
    {
    case DISCOVERY_REQUEST:
    case DISCOVERY_RESPONSE:
        size = 6;
        p = (char*)umalloc(size);
        break;

    case RETRIEVE_RECORD:
    case DELETE_RECORD:
        size = 8;
        p = (char*)umalloc(size);
        p[6] = messagePtr->recordIndex;
        p[7] = 0x00;
        break;
    
    case CREATE_RECORD:
        size = 26;
        p = (char*)umalloc(size);
        strcpy(p + 6, messagePtr->messageRecord);
        break;
    
    case RESPONSE:
        size = 28;
        p = (char*)umalloc(28);
        p[6] = messagePtr->status;
        p[7] = 0x00;
        strcpy(p + 8, messagePtr->messageRecord);
        break;
    } 

    p[0] = messagePtr->senderGroupId & 0xff;
    p[1] = (messagePtr->senderGroupId >> 8) & 0xff;
    p[2] = messagePtr->messageType;
    p[3] = messagePtr->requestNumber;
    p[4] = messagePtr->senderId;
    p[5] = messagePtr->destinationId;

    details.messageSize = size;
    details.messageContent = p;
    
    return details;
}



/**
 * State machine for handling transmitting messages
*/
fsm transmitter (message * messagePtr) {

    state Transmit_Message:
        messageDetails details = getMessageDetials(messagePtr);
        
        address spkt;

        // populate packet pointer
        spkt = tcv_wnp (Transmit_Message, sfd,  details.messageSize + 4);
        spkt [0] = 0;
        char * p = (char*) (spkt+1); // skip first 2 bytes
        memcpy(p, details.messageContent, details.messageSize);

        // printByteArray(p, 6);
        
        tcv_endp (spkt);

    state Confirm_Transmission:
        finish;
}

message * initialize_response(message * receiveMessagePtr){
    
    message *response = (message *)umalloc(sizeof(message));

	response->senderGroupId = groupId;
	response->messageType = RESPONSE;
	response->requestNumber = receiveMessagePtr->requestNumber;
	response->senderId = nodeId;
	response->destinationId = receiveMessagePtr->senderId;
	
    strcpy(response->messageRecord,"\0");
}

message *add_entry(message *receiveMessagePtr){
	message *response = initialize_response(receiveMessagePtr);

	if(recordCount >= MAX_RECORDS){
		response->status = 0x02;
		return response;
	}

    database[recordCount].ownerId = receiveMessagePtr->senderId;
    database[recordCount].timeStamp = time(NULL);
    strcpy(database[recordCount].recordMessage, receiveMessagePtr->messageRecord);
	
    recordCount++;
	
    response->status = 0x01;
	
    return response;
}

message *delete_entry(message *receiveMessagePtr){
	message *response = initialize_response(receiveMessagePtr);
	
    if(recordCount == 0){
		response->status = 0x03;
		return response;
	}

	if(receiveMessagePtr->recordIndex >= recordCount){ //Nothing here
		response->status = 0x04;
		return response;
	}
	
    response->status = 0x01;
	
    //delete the element
	database[receiveMessagePtr->recordIndex] = database[recordCount-1];
	recordCount--;

	return response;
}

message *retrieve_entry(message *receiveMessagePtr){
	message *response = initialize_response(receiveMessagePtr);
	
    if(recordCount == 0){
		response->status = 0x03;
		return response;
	}
	
    if(receiveMessagePtr->recordIndex >= recordCount){ //Nothing here
		response->status = 0x04;
		return response;
	}
	
    response->status = 0x01;
	
    strcpy(response->messageRecord, database[receiveMessagePtr->recordIndex].recordMessage);
	
    return response;
}

/**
 * This FSM will run and listen to all incoming packets and sort them as required
 */
fsm receiver {
    
    address rpkt;

    char * payload;

    message * receiveMessagePtr;

    message * response;

    message * discoveryResponseMessage;

    state Initialize_Receiver:
        receiveMessagePtr = (message *) umalloc(sizeof(message));

        discoveryResponseMessage = (message *) umalloc(sizeof(message));

    state Receiving:

        // wait for a message
        rpkt = tcv_rnp (Receiving, sfd);

        // start parcing the payload
        // skip first 2 bytes and cast to char pointer
        payload = (char *) (rpkt+1);

        // parce the payload
        receiveMessagePtr -> senderGroupId = (short) *payload;
        receiveMessagePtr -> messageType = *(payload+2);
        receiveMessagePtr -> requestNumber = *(payload+3);
        receiveMessagePtr -> senderId = *(payload+4);
        receiveMessagePtr -> destinationId = *(payload+5);

        // checks to see if recived packet belongs to the Group, if not returns to state finish 
        if (receiveMessagePtr -> senderGroupId != groupId){
            proceed Finish;
        }

    state Processing:

        
        
        // switches to the responce type
        switch (receiveMessagePtr -> messageType) {
            
        case 0:
            discoveryResponseMessage->senderGroupId = groupId;
            discoveryResponseMessage->messageType = 1;
            discoveryResponseMessage->requestNumber = receiveMessagePtr -> requestNumber;
            discoveryResponseMessage->senderId = nodeId;
            discoveryResponseMessage->destinationId = receiveMessagePtr -> senderId;
            call transmitter(discoveryResponseMessage, Finish);
            break;

        case 1:
            if(receiveMessagePtr -> destinationId == nodeId && receiveMessagePtr -> requestNumber == currentRequestNumber) {
                neighbours[receiveMessagePtr -> senderId] = 1;
                neighbourCount++;
            }

            break;

        case 2:
            // proceeds to finish if this this node was't the intended recipient
            if (receiveMessagePtr -> destinationId != nodeId){
                proceed Finish;
            }

            strcpy(receiveMessagePtr -> messageRecord, payload+6);

	        call transmitter(add_entry(receiveMessagePtr), Finish);
            break;
        
        case 3:
            if (receiveMessagePtr -> destinationId != nodeId) {
                proceed Finish;
            }

            receiveMessagePtr -> recordIndex = *(payload+6);
	        //response = delete_entry();
	        call transmitter(delete_entry(receiveMessagePtr), Finish);
            break;
        
        case 4:
            if (receiveMessagePtr -> destinationId != nodeId){
                proceed Finish;
            }

            receiveMessagePtr -> recordIndex = *(payload+6);
	        //response = retrieve_entry();
	        call transmitter(retrieve_entry(receiveMessagePtr), Finish);
            break;

        case 5:
            // filter out all packets that are not part of the currentRequestNumber
            if (receiveMessagePtr -> requestNumber != currentRequestNumber){
                proceed Finish;
            }

            receiveMessagePtr -> status = *(payload+6);
            strcpy(receiveMessagePtr -> messageRecord, payload+8);

            currentRequestNumber = 0;
	    
            if(currentProtocol == CREATE_RECORD){
                proceed Parse_Create_Record;    
            }else if(currentProtocol == DELETE_RECORD){
                proceed Parse_Delete_Record;
            }else if(currentProtocol == RETRIEVE_RECORD){
                proceed Parse_Retrieve_Record;
            }
                break;
            }
        
    state Finish:
        if(response != NULL) {
            ufree(response);
        }
        // clear memory and return back to reciving
        tcv_endp (rpkt); // I think this frees the memory
        proceed Receiving;
	
    state Parse_Create_Record:
        if(receiveMessagePtr->status == 0x01){
            ser_outf(Parse_Create_Record, "\r\n Data Saved");	
        }else{
            ser_outf(Parse_Create_Record, "\r\n The record can't be saved on node %d", receiveMessagePtr->senderId);
        }
        proceed Finish;
	
    state Parse_Delete_Record:
        if(receiveMessagePtr->status == 0x01){
            ser_outf(Parse_Delete_Record, "\r\n Record Deleted");	
        }else{
            ser_outf(Parse_Delete_Record, "\r\n The record does not exist on node %d", receiveMessagePtr->senderId);
        }
        proceed Finish;
	
    state Parse_Retrieve_Record:
        if(receiveMessagePtr->status == 0x01){
            ser_outf(Parse_Retrieve_Record, "\r\n Record Received from %d: %s", receiveMessagePtr->senderId, receiveMessagePtr->messageRecord);	
        }else{
            ser_outf(Parse_Retrieve_Record, "\r\n The record does not exist on node %d", receiveMessagePtr->senderId);
        }
        proceed Finish;
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
   //srand((unsigned) time(&t));

   return (char)rand() % 0xff;
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

    message * findMessage;

    state Initialize:
        resetNeighbours();

        i = 0;
        sendCount = 0;
        currentRequestNumber = randomNumber();

        findMessage = (message*) umalloc(6);

        findMessage->senderGroupId = groupId;
        findMessage->messageType = DISCOVERY_REQUEST;
        findMessage->requestNumber = currentRequestNumber;
        findMessage->senderId = nodeId;
        findMessage->destinationId = 0;

    state Send_Discovery_Request:
        
        if(sendCount == 2) {
            currentRequestNumber = 0;
            proceed Display_Neighbours;
        }
        
        sendCount++;
        call transmitter(findMessage, Wait);

    state Wait:
        delay(3*SECOND, Send_Discovery_Request);
        release;

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

Boolean isNeighbour(char node) {
    if(neighbours[node] == 1) {
        return YES;
    }

    return NO;
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

    message * messagePtr;

    char currentRecord;

    state Initialize:
        recordCount = 0;

        nodeId = 1;
        groupId = 6;

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
        // Start receiver
        runfsm receiver;

    state Menu_Header:
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
            proceed Display_Records;
            break;
        
        case 'e':
        case 'E':
            recordCount = 0;
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

// - - - - - - - - - - - - Create Recrods - - - - - - - - - - - - - //    
    state Create_Record:
        currentProtocol = CREATE_RECORD;
        ser_outf(Create_Record, "Receiver node ID (1-25):");
    
    state Get_Receiver_Node:
        ser_inf(Get_Receiver_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId) && !isNeighbour(receiverId)) {
            proceed Create_Record;
        }

    state Prompt_Message:
        ser_outf(Prompt_Message, "Enter a message: ");

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
        proceed Prompt_Recieving_Node;

    state Retrieve_Record:
        currentProtocol = RETRIEVE_RECORD;
        ser_outf(Retrieve_Record, "Retrieve Record from Neighbour:\n\r");

    state Prompt_Recieving_Node:
        ser_outf(Prompt_Recieving_Node, "Neighbour node ID (1-25):");
    
    state Get_Receiving_Node:
        ser_inf(Get_Receiving_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId) && !isNeighbour(receiverId)) {
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
        currentRequestNumber = randomNumber();

        messagePtr -> senderGroupId = groupId;
        messagePtr -> messageType = currentProtocol;
        messagePtr -> requestNumber = currentRequestNumber;
        messagePtr -> senderId = nodeId;
        messagePtr -> destinationId = receiverId;

        call transmitter(messagePtr, Menu_Header);

        delay(3*SECOND, Menu_Header);
        release;

    state Display_Records:
        currentRecord = 0;
        if (recordCount > 0) {
            ser_outf(Display_Records, "Index\tTime Stamp\t\tOwner ID\tRecord Data\n");
        } else {
            ser_outf(Display_Records, "No Records to Display\n");
        }
    
    state Display_Record:
        if (currentRecord < recordCount) {
            ser_outf(Display_Record, "%d\t%d\t\t%c\t%s\n", currentRecord, database[currentRecord].timeStamp, database[currentRecord].ownerId, database[currentRecord].recordMessage);
        } else {
            proceed Menu_Header;
        }


}
