#include <stdio.h>
#include "data.h"

int main() {
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (verificaDataValida(dia, mes, ano) == 0) {
        printf("A data informada eh invalida\n");
    }
    else {
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);

        if (verificaBissexto(ano) == 1) {
            printf("O ano informado eh bissexto\n");
        }
        else {
            printf("O ano informado nao eh bissexto\n");
        }

        printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
    }
}