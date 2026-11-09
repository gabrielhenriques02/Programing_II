#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    void **data;
    int size;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector *v = (Vector *) calloc(1, sizeof(Vector));
    if (v != NULL) {
        v->data = NULL;
        v->size = 0;
        return v;
    }
    else {
        exit(1);
    }
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val) {
    v->data = (void **) realloc (v->data, (v->size + 1)*sizeof(val));
    v->data[v->size] = val;
    v->size++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i) {
    if (i < v->size && i >=0) {
        return v->data[i];
    }
    else {
        printf("invalid index");
        exit(1);
    }
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    return v->size;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    for (int i = 0; i < v->size; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}