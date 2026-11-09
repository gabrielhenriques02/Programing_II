#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_TAM_NOME 50

struct Aluno {
    char nome[MAX_TAM_NOME];
    float nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno() {
    tAluno *a = (tAluno *) calloc(1, sizeof(tAluno));
    if (a != NULL) {
        return a;
    }
    else {
        exit(1);
    }
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno) {
    aluno = (tAluno *) aluno;
    free(aluno);
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno) {
    //scanf("%s;%c;%f\n", aluno->nome, &aluno->genero, &aluno->nota);
    char nome[MAX_TAM_NOME];
    scanf("%[^;]",nome);
    strcpy(aluno->nome,nome);
    scanf(";%c;%f", &aluno->genero, &aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno) {
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}