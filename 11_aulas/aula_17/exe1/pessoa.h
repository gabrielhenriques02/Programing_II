#ifndef _PESSOA_
#define _PESSOA_

#define MAX_TAM_NOME 100
#define MAX_TAM_DATA 9
#define MAX_TAM_CPF 15

typedef struct Pessoa Pessoa;

Pessoa *criaPessoa(char *nome, char *dataNasc, char *cpf);


#endif