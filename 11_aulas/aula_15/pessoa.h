#ifndef _PESSOA_
#define _PESSOA_

#define MAX_TAM_NOME 100

typedef struct Pessoa Pessoa;

Pessoa *criaPessoa(char *nome, int idade);
void printPessoa(void *data);
void liberaPessoa(void *data);

#endif