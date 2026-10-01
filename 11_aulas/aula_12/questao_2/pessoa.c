#include <stdio.h>
#include "pessoa.h"

Pessoa* criaPessoa() {
    Pessoa p = {0};
    return p;
}

void liberaPessoa(Pessoa *p) {

}

char* getNome();

Data getData();

char* getCpf();

void setNome(Pessoa *p);

void setCpf(Pessoa *p);

void setData(Pessoa *p);