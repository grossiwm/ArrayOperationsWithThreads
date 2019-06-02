
#include "libs.h"

int main(void) {
    int *mainArray = alocateArray(MAX_SIZE);
    int sizeOfMainArray = MAX_SIZE;
    int sizeOfTestArray = sizeOfMainArray;

    fillArrayWithRandom(100, 1, mainArray, MAX_SIZE);
    int *testArray = getCopiedArray(mainArray, sizeOfTestArray);

    printf("\nMain Array:\n");
    printArray(mainArray, MAX_SIZE);

    printf("\nTest Array:\n");
    printArray(testArray, MAX_SIZE);

    if (!compareArrays(mainArray, testArray, sizeOfMainArray, sizeOfTestArray)) {
        printf("exiting...\n");
        return 1;
    } else {
        printf("continuing...\n");
    }

    printf("\nPerforming removals without threads for testing purposes:\n");

    wrapper *wrap = getWrapper(testArray, &sizeOfTestArray, checkIfEven);
    void *parameter = (void *) wrap;
    printf("\nRemoving evens...\n");
    removeWithCondition(parameter);

    if (!checkIfAnyHasProperty(testArray, &sizeOfTestArray, checkIfEven)) {
        printOk();
        printf("\nThere are no evens on the array. Continuing...\n");
    } else {
        printNotOk();
        printf("\nThe array still has evens. exiting...\n");
        return 2;
    }
    printArray(testArray, sizeOfTestArray);

    wrap = getWrapper(testArray, &sizeOfTestArray, checkIfPrime);
    parameter = (void *) wrap;
    printf("\nRemoving primes...\n");
    removeWithCondition(parameter);
    free(parameter);
    free(wrap);

    printf("\nRemoving primes...\n");
    removeWithCondition(parameter);
    if (!checkIfAnyHasProperty(testArray, &sizeOfTestArray, checkIfPrime)) {
        printOk();
        printf("\nThere are no primes on the array. Continuing...\n");
    } else {
        printNotOk();
        printf("\nThe array still has primes. exiting...\n");
        return 2;
    }

    printArray(testArray, sizeOfTestArray);
    printf("\nFinal test array:\n");
    printArray(testArray, sizeOfTestArray);


    printf("Press ENTER key to Continue\n");  
    getchar();  

    printf("\nPerforming removals with threads:\n");

    //intializing mutex
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    //Initilizing threads
    pthread_t evenRemoveThread, primeRemovalThread;

    wrapper4thread *wrap4firstThread = getWrapperWithMutex(mainArray, &sizeOfMainArray, checkIfEven, &mutex);
    void *parameter4firstthread = (void *) wrap4firstThread;

    wrapper4thread *wrap4secondThread = getWrapperWithMutex(mainArray, &sizeOfMainArray, checkIfPrime, &mutex);
    void *parameter4secondthread = (void *) wrap4secondThread;

    // creating the threads
    pthread_create(&evenRemoveThread, NULL,removeWithConditionWithMutex, parameter4firstthread);
    pthread_create(&primeRemovalThread, NULL, removeWithConditionWithMutex, parameter4secondthread);

    printf("\nMain Array before:\n");
    printArray(mainArray, sizeOfMainArray);

    pthread_join(evenRemoveThread, NULL);
    pthread_join(primeRemovalThread, NULL);

    free(wrap4firstThread);
    free(wrap4secondThread);
    free(parameter4firstthread);
    free(parameter4secondthread);


    printf("\nMain Array after:\n");
    printArray(mainArray, sizeOfMainArray);

    printf("\nTest Array: \n");
    printArray(testArray, sizeOfTestArray);

    printf("\nComparing main array with test array...\n");
    compareArrays(mainArray, testArray, sizeOfMainArray, sizeOfTestArray);

    return 0;
}