#include "events.h"
#include "message.h"

/* typedef struct {  
      UBYTE mode;
      UBYTE type;
      ULONG threshold;
      ULONG event_counter;
      UBYTE OPC;
      Semaphore semaphore;
      TVEC tasks;
      MsgIndex message;
      UBYTE nextEvent;
} ED_tdef;
*/


/* initialize all fields*/
ED_tdef ED_Table[MAX_EVENTS] = {
   {
      ENABLE, FREE_RUNNING, 1, 1,     OPC_RELEASE,  NA, 0x01, NA, NA      
   },
   {
      ENABLE, FREE_RUNNING, 1, 1,     OPC_SEND_MSG, NA,   NA,  TEMPERATURE, NA      
   },
};

/*fill the approproate indeces in the 10 milli-Second Events Table*/
IndexTable _10_mS_EVENT_Table[MAX_10mS_EVENT] = {
};
/*fill the approproate indeces in the 1 Second Events Table*/
IndexTable SEC_EVENT_Table[MAX_SEC_EVENT]    = { 0
};
/*fill the approproate indeces in the 1 Minute Events Table*/
IndexTable MIN_EVENT_Table[MAX_MIN_EVENT]    = {   
};
/*fill the approproate indeces in the 1 Hour Events Table*/
IndexTable HR_EVENT_Table[MAX_HR_EVENT]      = {
};

IndexTable EXT_EVENT_Table[MAX_EXT_EVENT]    = { 1    
};
