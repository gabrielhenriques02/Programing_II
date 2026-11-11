#include <stdio.h>
#include <string.h>
#include "receita.h"
#include "encaminhamento.h"
#include "exame.h"
#include "fila_imp.h"

int main() {
    FilaImp *f = criaFilaImp();
    float precoCaractere;
    char option[50];
    scanf("%f\n", &precoCaractere);
    //printf("%.2f\n", precoCaractere);

    while(1) {
        scanf("%[^\n]\n", option);
        //printf("guardou %s\n", option);

        if (strcmp(option, "RECEITA") == 0) {
            //printf("entrou na opcao RECEITA\n");
            Receita *r = leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        }
        else if (strcmp(option, "ENCAMINHAMENTO") == 0) {
            //printf("entrou na opcao RECEITA\n");
            Encaminhamento *r = leEncaminhamento();
            insereDocumentoFilaImp(f, r, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        }
        else if (strcmp(option, "EXAME") == 0) {
            //printf("entrou na opcao RECEITA\n");
            Exame *r = leExame();
            insereDocumentoFilaImp(f, r, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }
        else if (strcmp(option, "IMPRIME") == 0) {
            imprimeFilaImp(f);
        }
        else if (strcmp(option, "PRECO") == 0) {
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, precoCaractere));
        }
        else if (strcmp(option, "QUANTIDADE") == 0) {
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
        }
        else if (strcmp(option, "FIM") == 0) {
            break;
        }
    }

    desalocaFilaImp(f);

    return 0;
}