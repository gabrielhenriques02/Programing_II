#include <stdio.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

#define TAM_OPT 20

int main() {

    tLocadora locadora = criarLocadora();

    char option[TAM_OPT];

    while (1) {

        scanf("%[^\n]", option);

        if (strcmp(option, "Cadastrar") == 0) {

            char end;
            lerCadastroLocadora(locadora);
            
            if (scanf("%c", &end) == 1) {
                printf("\n");
                continue;
            }
            else {
                consultarLucroLocadora(locadora);
                break;
            }
        }

        else if (strcmp(option, "Alugar") == 0) {

            char end;
            lerAluguelLocadora(locadora);
            
            if (scanf("%c", &end) == 1) {
                printf("\n");
                continue;
            }
            else {
                consultarLucroLocadora(locadora);
                break;
            }
        }

        else if (strcmp(option, "Devolver") == 0) {

            char end;
            lerDevolucaoLocadora(locadora);
            
            if (scanf("%c", &end) == 1) {
                printf("\n");
                continue;
            }
            else {
                consultarLucroLocadora(locadora);
                break;
            }
        }

        else if (strcmp(option, "Estoque") == 0) {

            char end;
            consultarEstoqueLocadora(locadora);
            
            if (scanf("%c", &end) == 1) {
                printf("\n");
                continue;
            }
            else {
                consultarLucroLocadora(locadora);
                break;
            }
        }

        else {
            printf("deu ruim alguma coisa\n");
            break;
        }
    }
    
}