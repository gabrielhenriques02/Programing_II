#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    DataType *data;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector *v = (Vector *) calloc(1, sizeof(Vector));
    v->data = NULL;
    v->qtd = 0;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val) {
    v->data = (DataType*) realloc(v->data, (v->qtd + 1)*sizeof(DataType));
    v->data[v->qtd] = val;
    v->qtd++; 
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v) {
    if (v->qtd == 0) {
        return NULL;
    }
    else if (v->qtd == 1) {
        DataType d = v->data[0];
        v->data[0] = NULL;
        //v->data = (DataType*) realloc(v->data, (v->qtd - 1)*sizeof(DataType));
       //free(v->data[0]);
        v->qtd--;
        return d;
    }
    else {
        DataType d = v->data[0];
        for (int i = 0; i < v->qtd - 1; i++) {
            v->data[i] = v->data[i + 1];
        }
        //v->data[v->qtd - 1] = NULL;
        v->data = (DataType*) realloc(v->data, (v->qtd - 1)*sizeof(DataType));
        v->qtd--;
        return d;
    }
    
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i) {
    if (v->qtd <= i) {
        return v->data[i - 1];
    }
}
/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    for (int i = 0; i < v->qtd; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}