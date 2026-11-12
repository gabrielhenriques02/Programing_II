#include <stdio.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("dados.bin", "rb");
    int numeros[5];
    int elementos_lidos = fread(numeros, sizeof(int), 5, arquivo);
    printf("Elementos lidos: %d\n", elementos_lidos);
    for (int i = 0; i < elementos_lidos; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    fclose(arquivo);
    return 0;

}