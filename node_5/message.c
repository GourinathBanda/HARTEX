#include "message.h"

MCB_tdef MCB[MAX_MESSAGE] = {
   {
      0x60,
      (void*)&sourceBuf0,
      sizeof(sourceBuf0)
   },
   {
      0x42,
      (void*)&sourceBuf1,
      sizeof(sourceBuf1)
   },  
};

MsgSCB_tdef MsgSCB[MAX_MESSAGE] = {
   {
      0,
      0x60
   },
   {
      0,
      0x42
   },   
};
