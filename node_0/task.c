#include <avr/io.h>
#include <avr/interrupt.h>

#include "../kernel_0_0/TaskManager.h"

#include "task.h"

void (*start_task[MAX_TASK])(void) = { task0, task1};

void task0(void)
{
   sei();
   PORTB ^= 0x40;
   taskExit();  
}

void task1(void)
{
   sei();
   PORTB ^= 0x80;  
   taskExit();  
}

