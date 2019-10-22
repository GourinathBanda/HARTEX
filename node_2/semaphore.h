#ifndef __SEMAPHORES_H__
#define __SEMAPHORES_H__

#include "../kernel_0_2/include/typedef.h"

/*number of semaphores for event notification in sychronizing */
#define MAX_SYNCH_SEMAPHORE 16 
/*number of semaphores for message notification in communication*/
#define MAX_COMM_SEMAPHORE  16 

SCB_tdef SSCB[MAX_SYNCH_SEMAPHORE] = {
   {
     /*TWO FIELDS OF type  TVEC need to be intialized always the second field*/
     /*is zero*/  
   },
   {
      0x01,0x00  /*as of now the TVEC is 8 bit one */
   },
   {
      0xD1,0x00  /*as of now the TVEC is 8 bit one */
   },
   {
      0x0C,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0xB1,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x0A,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x09,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x0F,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0xF0,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x55,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x44,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x22,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x18,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x81,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0x61,0x00  /*as of now the TVEC is 8 bit one */
   },   
   {
      0xF0,0x00  /*as of now the TVEC is 8 bit one */
   }   
   
};


SCB_tdef CSCB[MAX_COMM_SEMAPHORE] = {
   {
      0
   },
   {
      1
   }   
};

#endif
