#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main() {
    int tamanho;
    scanf("%d\n", &tamanho);
    char *texto = CriaVetor(tamanho);
    ImprimeString(texto, tamanho);
    LeVetor(texto, tamanho);
    ImprimeString(texto, tamanho);
    LiberaVetor(texto);
}