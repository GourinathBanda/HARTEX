#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "typedef.h"

extern UWORD bit_vect[];

#define ENTER_CRITICAL { asm volatile ( \
		"in __tmp_reg__,__SREG__" "\n\t" 	\
		"cli" "\n\t" 				            \
		"push __tmp_reg__" "\n\t" 		      \
			: : );				               \
	}
								 
#define EXIT_CRITICAL { asm volatile (	\
		"pop __tmp_reg__"   	"\n\t"	      \
		"out __SREG__,__tmp_reg__" "\n\t"	\
			: : );				               \
	}

#endif
