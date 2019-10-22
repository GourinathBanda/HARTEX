#ifndef __INTEGRATED_EVENT_MANAGER_H__
#define __INTEGRATED_EVENT_MANAGER_H__

#include "include/typedef.h"

#define OPC_SIGNAL         0
#define OPC_RELEASE        1
#define OPC_SEND_MSG       2
#define OPC_EVENT_SWITCH   3

#define DISABLE      0
#define ENABLE       1
#define ONE_OFF      1
#define FREE_RUNNING 2

void sweepTable  (IndexTable *index_table, UBYTE length);
void eventManager(ED_tdef *EventDescriptor);

#endif
