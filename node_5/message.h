#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "../kernel_0_5/include/typedef.h"

#define TEMPERATURE (MsgIndex)0
#define PRESSURE    (MsgIndex)1

#define MAX_MESSAGE 2

struct temperature_s {
   UBYTE fieldA;
   UBYTE fieldB;
} sourceBuf0;

struct pressure_s {
   ULONG fieldA;
} sourceBuf1;

#endif

