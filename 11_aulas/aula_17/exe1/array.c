#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array {
    void **dados;
    int qtd;
};

Array *criaArray() {
    Array *a = (Array *) calloc(1, sizeof(Array));
    a->dados = NULL;
    a->qtd = 0;
}

void adicionaElementoArray(Array *a, void *dado) {
    a->dados = (void **) realloc(a->dados, (a->qtd + 1)*sizeof(void *));
    a->dados[a->qtd] = dado;
    a->qtd++;
}