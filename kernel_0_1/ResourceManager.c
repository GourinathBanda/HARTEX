/*
 * ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 * file: TaskManager.c, v 0.0 2003/05/08 
 */

#include <avr/interrupt.h>

#include "TaskManager.h"
#include "ResourceManager.h"
#include "ResourceManager_.h"

#include "include/typedef.h"
#include "include/global.h"

void lock(RESOURCE resource)
{
   ENTER_CRITICAL;
   if (RCB[resource].ceiling >= PI) {
      pushPiStack(PI);
      PI = RCB[resource].ceiling;                  
      BTV = (TVEC)~(BTV | (TVEC)PI_Table[PI+1]);
   }
   EXIT_CRITICAL;
}

void unlock(RESOURCE resource)
{
   ENTER_CRITICAL;
   if (RCB[resource].ceiling == PI) {
      popPiStack( &PI);
      BTV = (TVEC)~(BTV & (TVEC)PI_Table[PI+1]);
      preempt();                  
   }
   EXIT_CRITICAL;  
} 

void pushPiStack(SBYTE pi)
{
   ENTER_CRITICAL;
   PI_Stack[top++]= pi;
   EXIT_CRITICAL;
}

void popPiStack(SBYTE *pi)
{
   ENTER_CRITICAL;
   *pi = PI_Stack[--top];
   EXIT_CRITICAL;
}
