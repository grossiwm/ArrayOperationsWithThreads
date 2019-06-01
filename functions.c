#include "libs.h"

void printArray(int *array, int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }

    }
    printf(" ]\n");
}

void fillArrayWithRandom(int maxValue, int minValue, int *array, int length) {
    printf("\nGerando array aleatória... \n");
    srand(time(NULL));
    int r = rand();
    for( int i = 0; i < length; i++ ) {
        array[i] = ( rand() % maxValue + minValue );
    }
}

int *getCopiedArray(int *array2copy, int size) {
    int *copiedArray = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        copiedArray[i] = array2copy[i];
    }
    return copiedArray;
}

void removeFromArray(int *array, int *sizeOfArray, int index2remove) {
    for (int i = index2remove; i < *sizeOfArray - 1; i++) {
        array[i] = array[i+1];
    }
    *sizeOfArray -= 1;
}

int checkIfPrime(int number) {
    int i;
    if (number < 2) return false;
    for (i=2; i <= number/2; i++) {
        if (number % i == 0) return false;

    }
    return true;
}

int checkIfEven(int number) {
    int isEven = false;
    if (number % 2 == 0 && number != 0) {
        isEven = true;
    }
    return isEven;
}

void removeWithCondition(void *parameter) {
    wrapper *wrap = (wrapper *) parameter;
    int *array = wrap->array;
    int *sizeOfArray = wrap->sizeOfArray;
    int (*conditionChecker)(int) = wrap->conditionChecker;

    for (int i = 0; i < *sizeOfArray; i++) {
        if (conditionChecker(array[i])) {
            removeFromArray(array, sizeOfArray, i);
            i -= 1;
        }
    }
}

void *removeWithConditionWithMutex(void *parameter) {

    wrapper4thread *wrap = (wrapper4thread *) parameter;
    int *array = wrap->array;
    int *sizeOfArray = wrap->sizeOfArray;
    int (*conditionChecker)(int) = wrap->conditionChecker;
    pthread_mutex_t *mutex = wrap->mutex;

    pthread_mutex_lock(mutex);

    for (int i = 0; i < *sizeOfArray; i++) {
        if (conditionChecker(array[i])) {
            removeFromArray(array, sizeOfArray, i);
            i -= 1;
        }
    }

    pthread_mutex_unlock(mutex);
}



