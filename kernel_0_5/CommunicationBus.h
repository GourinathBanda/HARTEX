#ifndef __COMMUNICATION_BUS_H__
#define __COMMUNICATION_BUS_H__

#include "include/typedef.h"

void  broadcast(MsgIndex message); 
UBYTE receive  (MsgIndex message);

void* getMsgSourceBuffer     (MsgIndex message);
void* getMsgDestinationBuffer(void);
UBYTE getMsgLength           (MsgIndex message);

#endif
