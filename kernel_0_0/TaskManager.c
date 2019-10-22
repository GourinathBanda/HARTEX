/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: TaskManager.c, v 0.0 2003/05/08 
 */

#include <avr/interrupt.h>

#include "TaskManager.h"
#include "TaskManager_.h"

#include "include/global.h"

void preempt(void) 
{
   TVEC HP;

   ENTER_CRITICAL;			
   //if (ATV) {				   // Assumption: ATV is non zero value
   HP = find_msb(ATV);
   if (RT != NO_TASK) {			// there is running task
      if ((HP > SCP) && (HP > RT)) {// if SCP = -1, HP > SCP is always true and 
      					         //   check depends on HP > RT
                              // if SCP > -1 and HP > SCP then HP > RT is
                              //   also true
         //PTV |= (TVEC)bit_vect[RT];	// not needed
         STORE_CONTEXT;                
         STORE_RT;				
         RT = HP;                      

         (*start_task[RT])();	// just let it run

	      LOAD_RT;
         LOAD_CONTEXT;
   	   //PTV &= (TVEC)~bit_vect[RT];	// not needed
      }
   }
   else {
      RT = HP;
      (*start_task[RT])();		// just let HP run
   }
   //}
   EXIT_CRITICAL;
}

void schedule(void) 
{
   ENTER_CRITICAL;
   //if (ATV) {				// Assumption: ATV is non zero value
   RT = find_msb(ATV);
   
   (*start_task[RT])();			// just let it run
   
   //}
   EXIT_CRITICAL;
}

void release(TVEC tasks)
{
   ENTER_CRITICAL;
   ATV |= (TVEC)tasks;
   preempt();				// not necessary
   EXIT_CRITICAL;
}

void taskExit(void)
{
   cli();					// disable interrupts - necessary !
   ATV &= (TVEC)~bit_vect[RT];
   RT = NO_TASK;				// there is no task running in the system
}

void kernelStartUp(void) 
{
   sei();                              /* enable interrupts */

   while (TRUE) {
      while (ATV) {			// schedule all active tasks
         schedule();
      }
   }
}

UBYTE find_msb( TVEC vector)  	// fast, time constant routine 
{						// Assumption: vector is non zero value !!!
   if ( vector > 0x0F) { 		// TVEC is UBYTE - unsigned 8 bit
      if ( vector > 0x3F) {
	   if ( vector > 0x7F) {
            return 7;
         }
         else {
            return 6;
         }
      }
      else {
	   if ( vector > 0x1F) {
            return 5;
         }
         else {
            return 4;
         }
      }
   }
   else {
      if ( vector > 0x03) {
         if ( vector > 0x07) {
            return 3;
         }
         else {
            return 2;
         }
      }
      else {
	   if ( vector > 0x01) {
            return 1;
         }
         else {//if ( vector == 0x01){// uncomment if vector can be zero
            return 0;
         }
	   //else {
         //   return NO_TASK;
         //}
      }
   }
}

