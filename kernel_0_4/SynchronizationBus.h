/*new function or peimitivr signa() is added from this
 * version v 0.4 2003/05/17
 */

#ifndef __SYNCHRONIZATION_BUS_H__
#define __SYNCHRONIZATION_BUS_H__

#include "include/typedef.h"

extern SCB_tdef SCB[];

void signal_and_release(Semaphore semaphore, TVEC tasks);
UBYTE    test_and_reset(Semaphore semaphore);

#endif
