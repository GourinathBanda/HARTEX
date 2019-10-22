#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "../kernel_0_4/include/typedef.h"

#define RESOURCE0 (Resource)0
#define RESOURCE1 (Resource)1

#define MAX_RESOURCE 2

RCB_tdef RCB[MAX_RESOURCE] = {
   {
      0
   },
   {
      1
   }   
};

UBYTE PI_Stack[MAX_RESOURCE];

#endif
