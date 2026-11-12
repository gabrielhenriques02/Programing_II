#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "array.h"

struct Pessoa {
    char nome[MAX_TAM_NOME];
    char dataNasc[MAX_TAM_DATA];
    char cpf[MAX_TAM_CPF];
};

Pessoa *criaPessoa(char *nome, char *dataNasc, char *cpf) {
    Pessoa *p = (Pessoa *) calloc(1, sizeof(Pessoa));
    strcpy(nome, p->nome);
    strcpy(dataNasc, p->dataNasc);
    strcpy(cpf, p->cpf);
    return p;
}

Pessoa *lePessoa() {
    Pessoa *p = (Pessoa *) calloc(1, sizeof(Pessoa));
    scanf("%[^\n]\n", p->nome);
    scanf("%[^\n]\n", p->dataNasc);
    scanf("%[^\n]\n", p->cpf);
    return p;
}

Pessoa **criaArrayPessoas() {
    Pessoa **pessoas = NULL;
    return pessoas;
}

void adici(Array *array, void *dado) {
    dado = (Pessoa *) dado;

}

int salvaBinPessoa(void *dado, FILE *arq) {
    Pessoa *p = (Pessoa *) dado;
    fwrite(p->nome, sizeof(char), MAX_TAM_NOME, arq);
}