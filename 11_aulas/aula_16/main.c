#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimePalavras(char **palavras, int tam);
int comparaPalavras(const void* a, const void* b);

int main() {
    
    char *palavras[5] = {"eu", "tu", "ele", "nos", "vos"};
    int tam = 5;
    qsort(palavras, tam, sizeof(**palavras), comparaPalavras);

    imprimePalavras(palavras, tam);
}

void imprimePalavras(char **palavras, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("palavra %d: %s", i + 1, palavras[i]);
    }
}

int comparaPalavras(const void* a, const void* b) {
    char *x = ( char *)a;
    char *y = ( char *)b;

    return strcmp(x, y);
}