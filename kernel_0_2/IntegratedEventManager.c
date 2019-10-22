/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: IntegratedEventManager.c, v 0.0 2003/05/13 
 */





#include <avr/interrupt.h>

#include "IntegratedEventManager.h"
#include "IntegratedEventManager_.h"
#include "TaskManager.h"
#include "include/global.h"

void sweepTable(IndexTable *index_table, UBYTE length)
{
   //PORTB ^= 0x80;
   int i;
   
   for (i = 0; i < length; i++) {
      eventManager( &ED_Table[index_table[i]]);  
   }   
}

void eventManager(ED_tdef *EventDescriptor)
{
   //PORTB ^= 0x80;
   if(EventDescriptor->mode == ENABLE){/* If the event is enabled*/ 

      (EventDescriptor->event_counter)--;
                                       /* decrement the event counter*/

      if(EventDescriptor->event_counter == 0){
//         PORTB ^= 0x80;
         executeOPC(EventDescriptor);
         if(EventDescriptor->type == FREE_RUNNING){/*if event is in free running mode*/ 
              EventDescriptor->event_counter = EventDescriptor->threshold;
                                       /*reload the event counter*/
                                       /*with the threshold value*/
         }
        // else if (EventDescriptor->type == ONE_OFF) { /*if event is one-off type*/
            //executeOPC(EventDescriptor);
            //disable(EventDescriptor);
            //enableNext(EventDescriptor);
        // }         
      }     
   }
}

void executeOPC(ED_tdef *EventDescriptor)
{
              //   PORTB ^= 0x80;
   
   
   switch(EventDescriptor->OPC)
   {
      /*signal semaphores*/
      case OPC_SIGNAL:                        
//         signal_and_release(EventDescriptor->semaphore);
         break;
      /*release the tasks*/
      case OPC_RELEASE:                        
         release(EventDescriptor->tasks);
         break;
      /*send the message*/
      case OPC_SEND_MSG:                       
//       broadcast(EventDescriptor->message);
         break;
      /*if event was ONEOFF type*/
      case OPC_EVENT_SWITCH:                        
         disable(EventDescriptor);
         enableNext(EventDescriptor);
         break;   
   }   
}

                            
/* disables the event*/
void disable(ED_tdef *EventDescriptor)
{
   EventDescriptor->mode = DISABLE;    
}

/* enables that event to be started after the current event*/
void enableNext(ED_tdef *EventDescriptor)
{
   ED_Table[EventDescriptor->tasks].mode = ENABLE;
                                       /*when the event is one-off type the   */
                                       /*TASKS field contains the index of the*/
                                       /*next event to be enabled because the */
                                       /*EVENT is initialized in this manner  */       
}

/*enables the event*/
void enable(ED_tdef *EventDescriptor)
{
   EventDescriptor->mode = ENABLE;  
} 

