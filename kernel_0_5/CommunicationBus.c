 /*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: CommunicationBus.c, v 0.0 2003/05/12 
 */

#include <avr/interrupt.h>

#include "CommunicationBus.h"
#include "CommunicationBus_.h"

#include "TaskManager.h"

#include "include/typedef.h"
#include "include/global.h"

void msg_signal_and_release(Semaphore semaphore, TVEC tasks) 
{
   ENTER_CRITICAL;
   MsgSCB[semaphore].flags |= tasks;
   release(MsgSCB[semaphore].tasks);
   EXIT_CRITICAL;
}

UBYTE msg_test_and_reset(Semaphore semaphore) 
{
   ENTER_CRITICAL;
   if (MsgSCB[semaphore].flags & bit_vect[RT]) {
       MsgSCB[semaphore].flags &= ~bit_vect[RT];
                                       /*clear the flag corresponding to the RT*/ 
      EXIT_CRITICAL;
      return TRUE;
   }
   else {
      EXIT_CRITICAL;
      return FALSE;
   }
}


void broadcast(MsgIndex message) 
{
   ENTER_CRITICAL;
   msg_signal_and_release(message,MCB[message].receivers);
   EXIT_CRITICAL;
}

UBYTE receive(MsgIndex message)
{
   ENTER_CRITICAL;
   if (msg_test_and_reset(message)){
      copy_message(MCB[message].sourceBuffer,
                   TCB[RT].msgLocalBuffer, MCB[message].length);
      EXIT_CRITICAL;
      return TRUE;
   }
   else{
      EXIT_CRITICAL;
      return FALSE;
   }
  
}

void* getMsgSourceBuffer(MsgIndex message)
{
   return(MCB[message].sourceBuffer);
}

void* getMsgDestinationBuffer(void)
{
   return (TCB[RT].msgLocalBuffer);
}

UBYTE getMsgLength(MsgIndex message)
{
   return (MCB[message].length);
}

void copy_message( UBYTE *source, UBYTE *destination, UBYTE length)
{
   while(length--) {
      destination[length] = source[length];
   }
}
