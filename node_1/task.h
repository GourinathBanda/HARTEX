#ifndef __TASK_H__
#define __TASK_H__

#define TASK0 0
#define TASK1 1

#define TASK0V (TVEC)bit_vect[TASK0]
#define TASK1V (TVEC)bit_vect[TASK1]

#define MAX_TASK 2

void task0(void);
void task1(void);

#endif
