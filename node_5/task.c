#include <avr/io.h>
#include <avr/interrupt.h>

#include "../kernel_0_5/TaskManager.h"
#include "../kernel_0_4/ResourceManager.h"

#include "../kernel_0_5/include/typedef.h"
#include "../kernel_0_5/include/global.h"
#include "../kernel_0_5/SynchronizationBus.h"
#include "../kernel_0_5/CommunicationBus.h"

#include "task.h"
#include "message.h"
#include "resource.h" 
#include "semaphore.h"

TCB_tdef TCB[MAX_TASK] = {
   {
      (void*)0,
   },
   {
      (void*)0,
   },
   {
      (void*)&msgDestBuf2,
   },
   {
      (void*)0,
   },
   {
      (void*)0,
   },
   {
      (void*)&msgDestBuf5,
   },
   {
      (void*)&msgDestBuf6,
   },
   {
      (void*)0,
   }
};

void (*start_task[MAX_TASK])(void) = { task0, task1,task2,task3,task4,task5,task6,task7};

void delay(ULONG delay)
{
   while( delay--) {
      asm volatile ( "nop"::);
   }
}

void task0(void)
{
   sei();
   PORTB ^= 0x01;
   taskExit();
}

void task1(void)
{
   sei();
   PORTB ^= 0x02;
   taskExit();  
}

void task2(void)
{
   sei();
   PORTB ^= 0x04;
   taskExit();  
}

void task3(void)
{
   sei();
   PORTB ^= 0x08;
   taskExit();  
}

void task4(void)
{
   sei();
   PORTB ^= 0x10;
   taskExit();  
}

void task5(void)
{
   sei();
   PORTB ^= 0x20;
   struct pressure_s *tempPtr = getMsgSourceBuffer(PRESSURE);
   tempPtr->fieldA = 0xA5;
   broadcast(PRESSURE);
   taskExit();  
}

void task6(void)
{
   sei();
   PORTB ^= 0x40;
   if ( receive(PRESSURE)) {
      union msgDestBuf6_s *tempPtr = getMsgDestinationBuffer();
      PORTB = tempPtr->pressure.fieldA;
      delay(100000);
   }
   taskExit();  
}

void task7(void)
{
   sei();
   PORTB ^= 0x80;
   taskExit();  
}

