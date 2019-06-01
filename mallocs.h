
#ifndef THREADSFORARRAYHANDLING_MALLOCS_H
#define THREADSFORARRAYHANDLING_MALLOCS_H

int *alocateArray(int n);

wrapper *getWrapper(int *array, int *sizeOfTestArray, int (*conditionChecker)(int));

wrapper4thread *getWrapperWithMutex(int *array, int *sizeOfArray, int (*conditionChecker)(int), pthread_mutex_t *mutex);

#endif //THREADSFORARRAYHANDLING_MALLOCS_H
