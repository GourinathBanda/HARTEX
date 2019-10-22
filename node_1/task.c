#include <avr/io.h>
#include <avr/interrupt.h>

#include "../kernel_0_1/TaskManager.h"
#include "../kernel_0_1/ResourceManager.h"

#include "../kernel_0_1/include/typedef.h"
#include "../kernel_0_1/include/global.h"

#include "task.h"
#include "resource.h" 

void (*start_task[MAX_TASK])(void) = { task0, task1};

void delay(ULONG delay)
{
   while( delay--) {
      asm volatile ( "nop"::);
   }
}

void task0(void)
{
   sei();

   PORTB ^= 0x40;
   delay(90000);

   lock(RESOURCE0);
   release(TASK1V);

   PORTB ^= 0x40;
   delay(90000);

   unlock(RESOURCE0);

   PORTB ^= 0x40;
   delay(90000);

   taskExit();  
}

void task1(void)
{
   sei();

   PORTB ^= 0x80;  
   delay(50000);

   lock(RESOURCE1);

   PORTB ^= 0x80;  
   delay(50000);

   unlock(RESOURCE1);

   PORTB ^= 0x80;  
   delay(50000);

   taskExit();  
}

