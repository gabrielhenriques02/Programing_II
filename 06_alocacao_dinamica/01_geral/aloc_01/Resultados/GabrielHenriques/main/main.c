#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int tamanho;
    float media;
    scanf("%d\n", &tamanho);
    int *v = CriaVetor(tamanho);
    LeVetor(v, tamanho);
    media = CalculaMedia(v, tamanho);
    printf("%.2f\n", media);
    LiberaVetor(v);
    return 0;
}