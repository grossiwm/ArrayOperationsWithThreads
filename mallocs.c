#include "libs.h"

int *alocateArray(int n) {
    int *array = (int *) malloc(sizeof(int)*n);
    return array;
}

wrapper *getWrapper(int *array, int *sizeOfArray, int (*conditionChecker)(int)) {
    wrapper *parameterPointer = (wrapper *) malloc(sizeof(wrapper));
    parameterPointer->array = array;
    parameterPointer->sizeOfArray = sizeOfArray;
    parameterPointer->conditionChecker = conditionChecker;

    return parameterPointer;
}

wrapper4thread *getWrapperWithMutex(int *array, int *sizeOfArray, int (*conditionChecker)(int), pthread_mutex_t *mutex) {
    wrapper4thread *wrap = (wrapper4thread *) malloc(sizeof(wrapper));
    wrap->array = array;
    wrap->sizeOfArray = sizeOfArray;
    wrap->conditionChecker = conditionChecker;
    wrap->mutex = mutex;

    return wrap;
}