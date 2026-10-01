#ifndef _PESSOA_
#define _PESSOA_

#include "data.h"

#define MAX_TAM_NOME 100
#define TAM_CPF 15

typedef struct {
    char* nome[MAX_TAM_NOME];
    Data dataNasc;
    char* cpf[TAM_CPF];
} Pessoa;

Pessoa* criaPessoa();

void liberaPessoa();

char* getNome();

Data getData();

char* getCpf();

void setNome(Pessoa *p);

void setCpf(Pessoa *p);

void setData(Pessoa *p);

#endif