task.o task.d : task.c ../kernel_0_5/TaskManager.h \
  ../kernel_0_5/include/typedef.h ../kernel_0_4/ResourceManager.h \
  ../kernel_0_4/include/typedef.h ../kernel_0_5/include/global.h \
  ../kernel_0_5/SynchronizationBus.h ../kernel_0_5/CommunicationBus.h \
  task.h message.h resource.h semaphore.h
