#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__
 
#define TRUE  1
#define FALSE 0

typedef unsigned char   UBYTE;
typedef unsigned short  UWORD;
typedef unsigned long   ULONG;

typedef signed char     SBYTE;
typedef signed short    SWORD;
typedef signed long     SLONG;

typedef ULONG period;
typedef UBYTE TVEC;
typedef UBYTE RESOURCE;

typedef struct {
   SBYTE ceiling;
} RCB_tdef;

typedef struct {
   UBYTE mode;
   ULONG threshold;
   ULONG event_counter;
} SCB_tdef;

typedef struct {
   UBYTE mode;
   ULONG threshold;
   ULONG event_counter;   
} ED_tdef;

#endif
