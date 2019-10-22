#ifndef __RESOURCE_MANAGER__H__
#define __RESOURCE_MANAGER__H__

#include "include/typedef.h"

extern TVEC BTV;

SBYTE  PI = -1;
UBYTE  top = 0;                           /* top of stack index*/
 
extern RCB_tdef RCB[];

extern UBYTE PI_Stack[];

UWORD PI_Table[17] = { 0x0000, 0x0001, 0x0003, 0x0007,
                       0x000F, 0x001F, 0x003F, 0x007F,
                       0x00FF, 0x01FF, 0x03FF, 0x07FF,
                       0x0FFF, 0x1FFF, 0x3FFF, 0x7FFF,0xFFFF };

void pushPiStack(SBYTE pi);
void popPiStack (SBYTE *pi);

#endif
