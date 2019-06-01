
#ifndef THREADSFORARRAYHANDLING_FUNCTIONS_H
#define THREADSFORARRAYHANDLING_FUNCTIONS_H

typedef struct Wrapper wrapper;

void fillArrayWithRandom(int maxValue, int minValue, int *array, int length);

void printArray(int *array, int length);

int *alocateArray(int n);

int *getCopiedArray(int *array2copy, int size);

void removeFromArray(int *array, int *sizeOfArray, int index2remove);

int checkIfPrime(int number);

int checkIfEven(int number);

void removeWithCondition(void * wrap);

void *removeWithConditionWithMutex(void *parameter);

#endif //THREADSFORARRAYHANDLING_FUNCTIONS_H
