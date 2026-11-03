#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct Pessoa {
    char nome[MAX_TAM_NOME];
    int idade;
};

Pessoa *criaPessoa(char *nome, int idade) {
    Pessoa *p = (Pessoa *) calloc(1, sizeof(Pessoa));
    strcpy(p->nome, nome);
    p->idade = idade;
    return p;
}

void printPessoa(void *data) {
    Pessoa *p = (Pessoa *) data;
    printf("Nome: %s\n", p->nome);
    printf("idade: %d", p->idade);
}

void liberaPessoa(void *data) {
    Pessoa *p = (Pessoa *) data;
    free(p);
}
