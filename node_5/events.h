/*
 * ----------------------------------------------------------------------------
 * with 8 events initialized
 * the first 7 events in the ED_Table are time based events releasing tasks
 * as mentioned by the tasks vector with them
 * the last event is around external event notified by the External Interrupt
 * ----------------------------------------------------------------------------
 * file: Events.h, v 0.0 2003/05/14 
 */


#ifndef __EVENT_DESCRIPTORS_H__
#define __EVENT_DESCRIPTORS_H__

#include "../kernel_0_5/IntegratedEventManager.h"

#include "../kernel_0_5/include/typedef.h"

#include "task.h"
#include "semaphore.h"

#define NA    0

#define MAX_10mS_EVENT 0 
#define MAX_SEC_EVENT  1 
#define MAX_MIN_EVENT  0 
#define MAX_HR_EVENT   0 

#define MAX_EXT_EVENT  1 

#define MAX_EVENTS (MAX_10mS_EVENT + MAX_SEC_EVENT + MAX_MIN_EVENT + MAX_HR_EVENT + MAX_EXT_EVENT)

#define EXT_EVENT_7  &ED_Table[1]

extern ED_tdef ED_Table[];

extern IndexTable _10_mS_EVENT_Table[];
extern IndexTable SEC_EVENT_Table   [];
extern IndexTable MIN_EVENT_Table   [];   
extern IndexTable HR_EVENT_Table    [];
extern IndexTable EXT_EVENT_Table   [];    

#endif
