#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array {
    void **data;
    int tam;
    func_ptr_desaloca desalocaData;

};

Array *criaArray(func_ptr_desaloca desaloca) {
    Array *a = (Array *) calloc(1, sizeof(Array));
    a->tam = 0;
    a->data = NULL;
    a->desalocaData = desaloca;
    return a;
}

void addElementoArray(Array *a, void *elem) {
    a->data = realloc(a->data, sizeof(void *) * (a->tam + 1));
    a->data[a->tam] = elem;
    a->tam++;
}

void *getElementoArray(Array *a, int pos) {
    if (pos < 0 || pos >= a->tam) {
        return NULL;
    }

    return a->data[pos];
}

int getTamArray(Array *a) {
    return a->tam;
}

void printArray(Array *a, func_ptr_print printData) {
    for (int i = 0; i < a->tam; i++) {
        printData(a->data[i]);
    }
}

void liberaArray(Array *a) {
    for (int i = 0; i < a->tam; i++) {
        a->desalocaData(a->data[i]);
    }

    free(a->data);
    free(a);
}