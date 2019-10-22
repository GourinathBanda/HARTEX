#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "../kernel_0_4/include/typedef.h"

#define TEMPERATURE (MsgIndex)0
#define MESSAGE1 (MsgIndex)1

#define MAX_MESSAGE 2

struct temperature {
   UBYTE fieldA;
   UBYTE fieldB;
} sourceBuf0;

struct sourceBuf1_s {
   ULONG field;
} sourceBuf1;

MCB_tdef MCB[MAX_MESSAGE] = {
   {
      0x01,
      (void*)&sourceBuf0,
      sizeof(sourceBuf0)
   },
   {
      0x02,
      (void*)&sourceBuf1,
      sizeof(sourceBuf1)
   }   
};

SCB_tdef CSCB[MAX_MESSAGE] = {
   {
      0,
      0
   },
   {
      0,
      0
   }   
};

#endif