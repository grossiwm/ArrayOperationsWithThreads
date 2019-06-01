//
// Created by Gabriel Rossi Lopes on 01/06/19.
//

#include "libs.h"

int compareArrays(int *array1, int *array2, int n1, int n2) {
    int sameSize;
    int sameArray;

    if (n1 == n2) {
        sameSize = 1;
    } else {
        sameSize = 0;
        printNotOk();
        printf("\nDifferent size arrays. ");
        return 0;
    }

    for (int i = 0; i < n1; i++) {
        if (array1[i] != array2[i]) {
            printf("\nArrays are not the same. ");
            printNotOk();
            return 0;
        }
    }
    printOk();
    printf("\nArrays are the same. ");
    return 1;
}

int checkIfAnyHasProperty(int *array, int *sizeOfArray, int (*conditionChecker)(int)) {
    for (int i = 0; i < *sizeOfArray; i++) {
        if (conditionChecker(array[i])) {
            return 1;
        }
    }
    return 0;
}

void printOk() {
    printf(""
           "┌─┐┬┌─\n"
           "│ │├┴┐\n"
           "└─┘┴ ┴"
           "");
}


void printNotOk() {
    printf(""
           "┌┐┌┌─┐┌┬┐  ┌─┐┬┌─\n"
           "││││ │ │   │ │├┴┐\n"
           "┘└┘└─┘ ┴   └─┘┴ ┴"
           "");
}