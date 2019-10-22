#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__
 
#define TRUE  1
#define FALSE 0

#define RAISE 1
#define CLEAR 0

typedef unsigned char   UBYTE;
typedef unsigned short  UWORD;
typedef unsigned long   ULONG;

typedef signed char     SBYTE;
typedef signed short    SWORD;
typedef signed long     SLONG;

typedef ULONG period;
typedef UBYTE TVEC;
typedef UBYTE Resource;

typedef UBYTE Semaphore;

typedef UBYTE EventIndex;

typedef UBYTE MsgIndex;

typedef struct {
   SBYTE ceiling;
} RCB_tdef;

typedef struct {
   TVEC flags;
   TVEC tasks;
} SCB_tdef;

typedef struct {
   UBYTE mode;
   UBYTE type;
   ULONG threshold;
   ULONG event_counter;
   UBYTE OPC;
   SCB_tdef semaphore;
   TVEC tasks;
   MsgIndex message;
} ED_tdef;

typedef UBYTE IndexTable;

typedef UBYTE FLAG;

#endif
