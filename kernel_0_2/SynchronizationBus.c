#include <avr/interrupt.h>

#include "SynchronizationBus.h"
#include "SynchronizationBus_.h"

#include "include/global.h"

void signal_and_release(SEMAPHORE semaphore,TVEC tasks) 
{
   ENTER_CRITICAL;
   SCB[semaphore].flags = SCB[semaphore].flags | tasks ;
   ATV = ATV | SCB[semaphore].tasks; 			
   EXIT_CRITICAL;
}

UBYTE test_and_reset(SEMAPHORE semaphore) 
{
   ENTER_CRITICAL;
   if (SCB[semaphore].flags[RT] == 1) {
      
      SCB[semaphore].flags[RT]=0;
      return TRUE;
   }
   else {
      return FALSE;
   }
   EXIT_CRITICAL;
}

