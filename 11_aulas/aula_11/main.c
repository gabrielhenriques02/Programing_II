#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *nome = (char*) malloc(100 * sizeof(char));
    strcpy(nome, "Anakin");
    printf("- Nome salvo: %s\n", nome);

    FILE *f = fopen("saida.txt", "w");
    fprintf(f, "%s", nome);
    fclose(f);

    free(nome);
    //free(f);

    return 0;
}

