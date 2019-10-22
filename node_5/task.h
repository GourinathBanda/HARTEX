#ifndef __TASK_H__
#define __TASK_H__

#include "message.h"

#define TASK0 0
#define TASK1 1
#define TASK2 2
#define TASK3 3
#define TASK4 4
#define TASK5 5
#define TASK6 6
#define TASK7 7

#define TASK0V (TVEC)bit_vect[TASK0]
#define TASK1V (TVEC)bit_vect[TASK1]
#define TASK2V (TVEC)bit_vect[TASK2]
#define TASK3V (TVEC)bit_vect[TASK3]
#define TASK4V (TVEC)bit_vect[TASK4]
#define TASK5V (TVEC)bit_vect[TASK5]
#define TASK6V (TVEC)bit_vect[TASK6]
#define TASK7V (TVEC)bit_vect[TASK7]

#define MAX_TASK 8

void task0(void);
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);
void task7(void);

union msgDestBuf6_s {
   struct temperature_s temperature; 
   struct pressure_s    pressure; 
} msgDestBuf6;

union msgDestBuf5_s {
   struct temperature_s temperature; 
} msgDestBuf5;

union msgDestBuf2_s {
   struct pressure_s pressure; 
} msgDestBuf2;

#endif
