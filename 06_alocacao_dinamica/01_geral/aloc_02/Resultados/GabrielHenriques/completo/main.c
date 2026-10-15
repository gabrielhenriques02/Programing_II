#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int linhas, colunas;
    scanf("%d %d\n", &linhas, &colunas);
    //printf("linhas: %d\ncolunas: %d\n", linhas, colunas);
    int **matriz = CriaMatriz(linhas, colunas);
    LeMatriz(matriz, linhas, colunas);
    /*printf("matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("matriz transposta:\n");*/
    ImprimeMatrizTransposta(matriz, linhas, colunas);
    LiberaMatriz(matriz, linhas);
}