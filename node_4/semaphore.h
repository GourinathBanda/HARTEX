#ifndef __SEMAPHORES_H__
#define __SEMAPHORES_H__

#include "../kernel_0_4/include/typedef.h"

/*number of semaphores for event notification in sychronizing */
#define MAX_SYNCH_SEMAPHORE 16 

#define SEM0  (Semaphore)0
#define SEM1  (Semaphore)1
#define SEM2  (Semaphore)2
#define SEM3  (Semaphore)3
#define SEM4  (Semaphore)4
#define SEM5  (Semaphore)5
#define SEM6  (Semaphore)6
#define SEM7  (Semaphore)7
#define SEM8  (Semaphore)8
#define SEM9  (Semaphore)9
#define SEM10 (Semaphore)10
#define SEM11 (Semaphore)11
#define SEM12 (Semaphore)12
#define SEM13 (Semaphore)13
#define SEM14 (Semaphore)14
#define SEM15 (Semaphore)15




SCB_tdef SCB[MAX_SYNCH_SEMAPHORE] = {
   {
      0x00,0x00
   },
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   },   
   {
      0x00,0x00/*as of now the TVEC is 8 bit one */
   }      
};

#endif

