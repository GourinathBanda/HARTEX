/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: IntegratedEventManager.c, v 0.4 2003/05/17 
 * signal() function is  added from this version
 */


#include <avr/interrupt.h>

#include "SynchronizationBus.h"
#include "SynchronizationBus_.h"

#include "TaskManager.h"

#include "include/typedef.h"
#include "include/global.h"

void signal_and_release(Semaphore semaphore, TVEC tasks) 
{
   ENTER_CRITICAL;
   SCB[semaphore].flags |= tasks;
   release(SCB[semaphore].tasks);
   EXIT_CRITICAL;
}

UBYTE test_and_reset(Semaphore semaphore) 
{
   ENTER_CRITICAL;
   //PORTB  ^= 0x80;
   if (SCB[semaphore].flags & bit_vect[RT]) {
       SCB[semaphore].flags &= ~bit_vect[RT];
                                       /*clear the flag corresponding to the RT*/ 
      EXIT_CRITICAL;
      return TRUE;
   }
   else {
      EXIT_CRITICAL;
      return FALSE;
   }
}

