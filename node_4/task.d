task.o task.d : task.c ../kernel_0_4/TaskManager.h \
  ../kernel_0_4/include/typedef.h ../kernel_0_4/ResourceManager.h \
  ../kernel_0_4/include/global.h ../kernel_0_4/SynchronizationBus.h \
  task.h resource.h defines.h
