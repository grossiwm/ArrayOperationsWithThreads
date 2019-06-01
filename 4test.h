
#ifndef THREADSFORARRAYHANDLING_4TEST_H
#define THREADSFORARRAYHANDLING_4TEST_H

int compareArrays(int *array1, int *array2, int n1, int n2);

int checkIfAnyHasProperty(int *array, int *sizeOfArray, int (*conditionChecker)(int));

void printOk();

void printNotOk();

#endif //THREADSFORARRAYHANDLING_4TEST_H
