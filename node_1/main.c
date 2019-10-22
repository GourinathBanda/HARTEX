/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: main.c, v 0.0 2003/05/08 
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

#include "../kernel_0_1/TaskManager.h"
#include "../kernel_0_1/ResourceManager.h"

#include "../kernel_0_1/include/typedef.h"
#include "../kernel_0_1/include/global.h"

#include "task.h"

SIGNAL(SIG_INTERRUPT7)
{
   release(TASK1V);
}

SIGNAL(SIG_INTERRUPT6)
{
   release(TASK0V);
}

void hd_init(void)
{
   DDRB  = 0xFF;                       /* 0-7 output */
   PORTB = 0x00;
   DDRD  = 0x00;                       /* 0-7 input */
   
   EIMSK |= (1<<INT7) | (1<<INT6); 		/* enable 6, 7 external interrupts */
   EICR  |= (1<<ISC71) | (1<<ISC61);  	/* interrupt request for INT7 ,INT6 */ 
                                       /* on falling edge */
}

int main(void)
{
   hd_init();

//   while(1) {  }
   kernelStartUp();

   return 0;
}

