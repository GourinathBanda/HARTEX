#ifndef __EVENT_DESCRIPTORS_H__
#define __EVENT_DESCRIPTORS_H__

#include "../kernel_0_2/IntegratedEventManager.h"

#include "../kernel_0_2/include/typedef.h"
#include "task.h"

#define MAX_10mS_EVENT 0 
#define MAX_SEC_EVENT  2 
#define MAX_MIN_EVENT  0 
#define MAX_HR_EVENT   0 

#define MAX_EXT_EVENT  0 

#define MAX_EVENTS (MAX_10mS_EVENT + MAX_SEC_EVENT + MAX_MIN_EVENT + MAX_HR_EVENT + MAX_EXT_EVENT)

/*typedef struct {
   UBYTE mode;
   UBYTE type;
   ULONG threshold;
   ULONG event_counter;
   UBYTE OPC;
   SCB_tdef semaphore;
   TVEC tasks;
   MsgIndex message;
} ED_tdef;  */


/* initialize all fields*/
ED_tdef ED_Table[MAX_EVENTS] = {
   {
     ENABLE, FREE_RUNNING, 1, 1, OPC_RELEASE, {0x00,0x00}, 0x01, 0                                  
   },
   {
     ENABLE, FREE_RUNNING, 2, 2, OPC_RELEASE, {0x00,0x00}, 0x02, 0      
   }                                      
};

/*fill the approproate indeces in the 10 milli-Second Events Table*/
IndexTable _10_mS_EVENT_Table[MAX_10mS_EVENT] = { 
};
/*fill the approproate indeces in the 1 Second Events Table*/
IndexTable SEC_EVENT_Table[MAX_SEC_EVENT]    = {0,1
};
/*fill the approproate indeces in the 1 Minute Events Table*/
IndexTable MIN_EVENT_Table[MAX_MIN_EVENT]    = {
};
/*fill the approproate indeces in the 1 Hour Events Table*/
IndexTable HR_EVENT_Table[MAX_HR_EVENT]      = {
};

IndexTable EXT_EVENT_Table[MAX_EXT_EVENT] = {
};
#endif
