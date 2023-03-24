#include <time.h>

#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"

#include "phys_cc1350.h"
#include "plug_null.h"

#define MAX_RECORDS 40

char nodeId;
short groupId;

typedef struct {
    time_t timeStamp;
    byte ownerId;
    byte message[20];
} record;

record database[MAX_RECORDS];

int recordCount;

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
"Selection:";

    char receiverId;

    state Initialize:
        recordCount = 0;

        nodeId = 1;
        groupId = 1;

    state Menu_Header:
        receiverId = 0;
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
            diag("Find neighbours");
            break;
        
        case 'c':
        case 'C':
            diag("Create Record on Neighbour");
            break;

        case 'd':
        case 'D':
            diag("Delete Record on Neighbour");
            break;

        case 'r':
        case 'R':
            diag("Retrieve Record on Neighbour");
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
    
    state Set_Group_ID:
        ser_outf(Set_Group_ID, "New Group ID: ");
    state Get_Group_ID:
        ser_inf(Get_Group_ID, "%d", &groupId);

        proceed Menu_Header;
    
    state Set_Node_ID:
        ser_outf(Set_Node_ID, "New node ID (1-25):");
    
    state Get_Node_ID:
        ser_inf(Get_Node_ID, "%d", &nodeId);

        if (!isValidNodeId(nodeId)) {
            proceed Set_Node_ID;
        }

        proceed Menu_Header;

}