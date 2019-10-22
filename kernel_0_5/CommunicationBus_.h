#ifndef __COMMUNICATION_BUS__H__
#define __COMMUNICATION_BUS__H__

#include "include/typedef.h"

extern TCB_tdef       TCB[];

extern MCB_tdef       MCB[];
extern MsgSCB_tdef    MsgSCB[];
extern volatile UBYTE RT;

void  msg_signal_and_release(Semaphore semaphore, TVEC tasks); 
UBYTE msg_test_and_reset    (Semaphore semaphore); 

void copy_message( UBYTE *source, UBYTE *destination, UBYTE length);

#endif
