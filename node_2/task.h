#ifndef __TASK_H__
#define __TASK_H__

#define TASK0 0
#define TASK1 1
#define TASK2 2
#define TASK3 3


#define TASK0V (TVEC)bit_vect[TASK0]
#define TASK1V (TVEC)bit_vect[TASK1]
#define TASK2V (TVEC)bit_vect[TASK2]
#define TASK3V (TVEC)bit_vect[TASK3]


#define MAX_TASK 4

void task0(void);
void task1(void);
void task2(void);
void task3(void);


#endif
