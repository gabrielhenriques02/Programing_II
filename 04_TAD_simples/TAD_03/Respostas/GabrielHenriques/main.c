#include <stdio.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

#define TAM_OPT 20

int main() {

    tLocadora locadora = criarLocadora();

    char option[TAM_OPT];

    while (scanf("%[^ \n]\n", option) == 1) {

        //printf("valor guardado em option: %s\n", option);

        if (strcmp(option, "Cadastrar") == 0) {

            char end;
            locadora = lerCadastroLocadora(locadora);
            
            if (scanf("%c\n", &end) == 1) {
                printf("\n");
                continue;
            }
        }

        else if (strcmp(option, "Alugar") == 0) {

            char end;
            locadora = lerAluguelLocadora(locadora);
            
            if (scanf("%c\n", &end) == 1) {
                printf("\n");
                continue;
            }
        }

        else if (strcmp(option, "Devolver") == 0) {

            char end;
            locadora = lerDevolucaoLocadora(locadora);
            
            if (scanf("%c\n", &end) == 1) {
                printf("\n");
                continue;
            }
        }

        else if (strcmp(option, "Estoque") == 0) {

            char end;
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora(locadora);
            //printf("\n");
            
            if (scanf("%c\n", &end) == 1) {
                //printf("\n");
                continue;
            }
        }

        else {
            printf("deu ruim alguma coisa\n");
            break;
        }
    }

    consultarLucroLocadora(locadora);
    return 0;
    
}