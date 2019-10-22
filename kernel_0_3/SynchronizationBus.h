#ifndef __SYNCHRONIZATION_BUS_H__
#define __SYNCHRONIZATION_BUS_H__

#include "include/typedef.h"

void signal_and_release(SEMAPHORE semaphore,TVEC tasks);
UBYTE test_and_reset(SEMAPHORE semaphore);

#endif
