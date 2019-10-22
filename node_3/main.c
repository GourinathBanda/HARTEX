/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: main.c, v 0.0 2003/05/14
 * with completely working event manager 
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

#include "../kernel_0_3/TaskManager.h"
#include "../kernel_0_3/ResourceManager.h"
#include "../kernel_0_3/IntegratedEventManager.h"

#include "../kernel_0_3/include/typedef.h"
#include "../kernel_0_3/include/global.h"

#include "task.h"
#include "events.h"

SIGNAL(SIG_INTERRUPT7)
{
   //eventManager( &ED_Table[2]);
   sweepTable(EXT_EVENT_Table,1);  
   //release(TASK3V);
}

SIGNAL(SIG_INTERRUPT6)
{
   release(TASK6V);
}

/*also write here the external interrupts that are linked with the */
/*events in the event descriptor table */

/* ISR_External_event_X ()
   {
      Event_Manager(ED_Table[x]);
   }
*/


/*TIMER INTERRUPT HANDLING TIMING EVENTS */
/*this interrupt should occurs every 10 milli seconds*/

SIGNAL (SIG_OUTPUT_COMPARE1A)          
{
   static FLAG msec_FLAG = CLEAR;
   static FLAG sec_FLAG  = CLEAR;
   static FLAG min_FLAG  = CLEAR;
   static FLAG hr_FLAG   = CLEAR;
   static UBYTE msec = 0;
   static UBYTE sec  = 0;
   static UBYTE min  = 0;
  
   msec_FLAG = RAISE;                  /*raise the 10msec_FLAG*/ 
   msec++;
   if(msec == 100){
      //PORTB ^= 0x80;
      sec_FLAG = RAISE;                /*raise the sec_FLAG*/   
      sec++;
      msec = 0 ;                       /*reset the milliSecond counter*/
   }
   if(sec == 60){
      min_FLAG = RAISE;                /*raise the min_FLAG*/
      min++;
      sec = 0 ;                        /*reset the second counter*/
   }

   if(min == 60){
      hr_FLAG = RAISE;                 /*raise the min_FLAG*/
      min = 0 ;                        /*reset the minute counter*/
   }   

  /*  EVENT MANGER INVOCATION*/
   if (msec_FLAG)           sweepTable(_10_mS_EVENT_Table, MAX_10mS_EVENT);

   if (sec_FLAG == RAISE)   sweepTable(SEC_EVENT_Table, MAX_SEC_EVENT);

   if (min_FLAG)            sweepTable(MIN_EVENT_Table, MAX_MIN_EVENT);

   if (hr_FLAG)             sweepTable(HR_EVENT_Table, MAX_HR_EVENT);

   /*clearFlags*/
   
   msec_FLAG = CLEAR;
   sec_FLAG  = CLEAR;
   min_FLAG  = CLEAR;
   hr_FLAG   = CLEAR;
      
}


void hd_init(void)
{
   UWORD ocr = 40000; 
   DDRA  = 0xFF;                       /* 0-7 output */

   DDRB  = 0xFF;                       /* 0-7 output */
   PORTB = 0xFF;
   DDRD  = 0x00;                       /* 0-7 input */
   
   EIMSK |= (1<<INT7) | (1<<INT6); 		/* enable 6, 7 external interrupts */
   EICR  |= (1<<ISC71) | (1<<ISC61);  	/* interrupt request for INT7 ,INT6  
                                          on falling edge */

   OCR1AH = (UBYTE)((ocr >> 8)& 0xFF);
   OCR1AL = (UBYTE)(ocr & 0x00FF);

   TCCR1B = (1<<CTC1)|(0<<CS12)|(0<<CS11)|(1<<CS10);
                                       /* prescale factor 1 and counter cleared*/
   
   TIMSK  |= (1<<OCIE1A);              /* Enable Timer1 Output Compare Match 
                                          Interrupt*/   
   

}

int main(void)
{
   hd_init();

//   while(1) {  }
   kernelStartUp();

   return 0;
}

