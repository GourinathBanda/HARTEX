main.o main.d : main.c ../kernel_0_5/TaskManager.h \
  ../kernel_0_5/include/typedef.h ../kernel_0_5/ResourceManager.h \
  ../kernel_0_5/IntegratedEventManager.h \
  ../kernel_0_5/SynchronizationBus.h ../kernel_0_5/CommunicationBus.h \
  ../kernel_0_5/include/global.h task.h message.h events.h semaphore.h
