#ifndef __TASK_MANAGER__H__
#define __TASK_MANAGER__H__

#include "include/typedef.h"

#define NO_TASK	((1 << (sizeof(TVEC)*8)) -1)	// RT value, set in task_exit()

volatile TVEC ATV;
volatile TVEC PTV;
volatile UBYTE RT;

volatile SBYTE SCP = -1;

extern void (*start_task[])(void);

#define STORE_RT     {	asm volatile (					\
		"push %0"  	"\n\t"			\
			: /*no outputs*/			\
			: "r" ((UBYTE)RT) );		\
	}

#define LOAD_RT     {	asm volatile (					\
		"pop %0"   	"\n\t"			\
			: "=r" ((UBYTE)RT)		\
			: /*no inputs*/);			\
	}

#define STORE_CONTEXT     {	asm volatile (					\
		"push R0"  	"\n\t"			\
		"push R1"  	"\n\t"			\
		"push R2"  	"\n\t"			\
		"push R3"  	"\n\t"			\
		"push R4"  	"\n\t"			\
		"push R5"  	"\n\t"			\
		"push R6"  	"\n\t"			\
		"push R7"  	"\n\t"			\
		"push R8"  	"\n\t"			\
		"push R9"  	"\n\t"			\
		"push R10" 	"\n\t"			\
		"push R11" 	"\n\t"			\
		"push R12" 	"\n\t"			\
		"push R13" 	"\n\t"			\
		"push R14" 	"\n\t"			\
		"push R15" 	"\n\t"			\
		"push R16" 	"\n\t"			\
		"push R17" 	"\n\t"			\
		"push R18" 	"\n\t"			\
		"push R19" 	"\n\t"			\
		"push R20" 	"\n\t"			\
		"push R21" 	"\n\t"			\
		"push R22" 	"\n\t"			\
		"push R23" 	"\n\t"			\
		"push R24" 	"\n\t"			\
		"push R25" 	"\n\t"			\
		"push R26" 	"\n\t"			\
		"push R27" 	"\n\t"			\
		"push R28" 	"\n\t"			\
		"push R29" 	"\n\t"			\
		"push R30" 	"\n\t"			\
		"push R31" 	"\n\t"			\
		"in __tmp_reg__,__SREG__" "\n\t" 	\
		"push __tmp_reg__" "\n\t" 		\
			: : );				\
	}

#define LOAD_CONTEXT     {	asm volatile (					\
		"pop __tmp_reg__"   	"\n\t"	\
		"out __SREG__,__tmp_reg__" "\n\t"	\
		"pop R31" 	"\n\t"			\
		"pop R30"  	"\n\t"			\
		"pop R29"  	"\n\t"			\
		"pop R28"  	"\n\t"			\
		"pop R27"  	"\n\t"			\
		"pop R26"  	"\n\t"			\
		"pop R25"  	"\n\t"			\
		"pop R24"  	"\n\t"			\
		"pop R23"  	"\n\t"			\
		"pop R22"  	"\n\t"			\
		"pop R21"  	"\n\t"			\
		"pop R20" 	"\n\t"			\
		"pop R19" 	"\n\t"			\
		"pop R18" 	"\n\t"			\
		"pop R17" 	"\n\t"			\
		"pop R16" 	"\n\t"			\
		"pop R15" 	"\n\t"			\
		"pop R14" 	"\n\t"			\
		"pop R13" 	"\n\t"			\
		"pop R12" 	"\n\t"			\
		"pop R11" 	"\n\t"			\
		"pop R10" 	"\n\t"			\
		"pop R9" 	"\n\t"			\
		"pop R8" 	"\n\t"			\
		"pop R7" 	"\n\t"			\
		"pop R6" 	"\n\t"			\
		"pop R5" 	"\n\t"			\
		"pop R4" 	"\n\t"			\
		"pop R3" 	"\n\t"			\
		"pop R2" 	"\n\t"			\
		"pop R1" 	"\n\t"			\
		"pop R0" 	"\n\t"			\
			: : );				\
	}

UBYTE find_msb( TVEC vector);
void preempt(void);
void schedule(void);

#endif
