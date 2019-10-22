#ifndef __INTEGRATED_EVENT_MANAGER_H__
#define __INTEGRATED_EVENT_MANAGER_H__

#include "include/typedef.h"

#define OPC_SIGNAL         0x01
#define OPC_RELEASE        0x02
#define OPC_SEND_MSG       0x04
#define OPC_ENABLE_EVENT   0x08

#define DISABLE      0
#define ENABLE       1

#define ONE_OFF      1
#define FREE_RUNNING 2

void sweepTable  (IndexTable *index_table, UBYTE length);
void eventManager(ED_tdef *EventDescriptor);

#endif
