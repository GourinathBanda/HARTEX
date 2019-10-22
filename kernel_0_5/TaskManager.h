#ifndef __TASK_MANAGER_H__
#define __TASK_MANAGER_H__

#include "include/typedef.h"

//volatile UBYTE RT;

void kernelStartUp(void);

void release(TVEC tasks);
void taskExit(void); 
void preempt(void);

#endif

