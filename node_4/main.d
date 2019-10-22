main.o main.d : main.c ../kernel_0_4/TaskManager.h \
  ../kernel_0_4/include/typedef.h ../kernel_0_4/ResourceManager.h \
  ../kernel_0_4/IntegratedEventManager.h \
  ../kernel_0_4/SynchronizationBus.h ../kernel_0_4/include/global.h \
  task.h events.h semaphore.h
