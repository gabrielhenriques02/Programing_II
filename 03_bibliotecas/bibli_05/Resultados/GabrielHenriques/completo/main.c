#include <stdio.h>
#include "string_utils.h"

int main() {
    //fluxo inicio do programa
    //capturando string do usuario
    char str[100];
    scanf(" %99[^\n]", str);

    //loop para o menu
    while (1) {
        //escolha do usuario
        int option = 0;
        //display menu
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
        scanf("%i", &option);

        //condicional da escolha
        switch (option) {
            //fluxo opcao 1 - Tamanho da string
            case 1: {
                printf("Tamanho da string: %i\n\n", string_length(str));
                break;
            }
            //fluxo opcao 2 - Copiar string
            case 2: {
                //atencao aqui: o vetor original de tamanho 100 foi copiado para um vetor com o tamanho exato da string.
                char dest[string_length(str) + 1];
                string_copy(str, dest);
                printf("String copiada: %s\n\n", dest);
                break;
            }
            //fluxo opcao 3 - Converter string para letras maiusculas
            case 3: {
                string_upper(str);
                printf("String convertida para maiusculas: %s\n\n", str);
                break;
            }
            //fluxo opcao 4 - Converter string para letras minusculas
            case 4: {
                string_lower(str);
                printf("String convertida para minusculas: %s\n\n", str);
                break;
            }
            //fluxo opcao 5 - Imprimir string ao contrario
            case 5: {
                string_reverse(str);
                printf("String invertida: %s\n\n", str);
                break;
            }
        }
        //condicao para encerrar o programa
        if (option == 6) {
            break;
        }
    }
    return 0;
}