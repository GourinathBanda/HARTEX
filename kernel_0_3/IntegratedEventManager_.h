#ifndef __INTEGRATED_EVENT_MANAGER__H__
#define __INTEGRATED_EVENT_MANAGER__H__

#include "include/typedef.h"

#define  DISABLE 0
#define  ENABLE  1

extern ED_tdef    ED_Table         [];
extern IndexTable _10_mS_EVENT_Table[];
extern IndexTable SEC_EVENT_Table  [];
extern IndexTable MIN_EVENT_Table  [];
extern IndexTable HR_EVENT_Table   [];

extern IndexTable EXT_EVENT_Table  [];

void executeOPC(ED_tdef *EventDescriptor);
void disable   (ED_tdef *EventDescriptor);
void enableNext(ED_tdef *EventDescriptor);


#endif
