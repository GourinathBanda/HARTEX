#include <avr/io.h>
#include <avr/interrupt.h>

#include "../kernel_0_3/TaskManager.h"
#include "../kernel_0_3/ResourceManager.h"

#include "../kernel_0_3/include/typedef.h"
#include "../kernel_0_3/include/global.h"

#include "task.h"
#include "resource.h" 

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

   PORTA ^= 0x01;
   PORTB ^= 0x04;  
  /* delay(150000);

  // lock(RESOURCE1);
  // release(TASK3V);
   PORTB ^= 0x04;  
   delay(150000);

   //unlock(RESOURCE1);

   PORTB ^= 0x04;  
   delay(150000);*/
   taskExit();  
}

void task3(void)
{
   sei();

   PORTB ^= 0x08;  
   //delay(50000);

  /* lock(RESOURCE1);*/

   //PORTB ^= 0x08;  
   //delay(50000);

   /*unlock(RESOURCE1);*/

   //PORTB ^= 0x08;  
   //delay(50000);

   taskExit();  
}

void task4(void)
{
   sei();

   PORTB ^= 0x10;
   /*delay(50000);

   PORTB ^= 0x10;
   delay(50000);

   PORTB ^= 0x10;*/

   taskExit();  
}


void task5(void)
{
   sei();

   PORTB ^= 0x20;

   taskExit();  
}

void task6(void)
{
   sei();

   PORTB ^= 0x40;
   delay(50000);
   PORTB ^= 0x40;
   delay(50000);
   PORTB ^= 0x40;
   taskExit();  
}


void task7(void)
{
   sei();

   PORTB ^= 0x80;
   delay(50000);

   PORTB ^= 0x80;
   delay(50000);

   PORTB ^= 0x80;

   taskExit();  
}

