
#ifndef THREADSFORARRAYHANDLING_STRUCTURES_H
#define THREADSFORARRAYHANDLING_STRUCTURES_H

typedef struct Wrapper {
    int *array;
    int *sizeOfArray;
    int (*conditionChecker)(int);
} wrapper;

typedef struct Wrapper4thread {
    int *array;
    int *sizeOfArray;
    int (*conditionChecker)(int);
    pthread_mutex_t *mutex;
} wrapper4thread;

#endif //THREADSFORARRAYHANDLING_STRUCTURES_H
