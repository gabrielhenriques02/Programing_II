#include <stdio.h>
#include "data.h"

int main() {
    //declarando variaveis do programa
    int dia1, mes1, ano1, dia2, mes2, ano2;
    //armazenando a primeira data
    scanf("%d/%d/%d\n", &dia1, &mes1, &ano1);
    //armazenando a segunda data
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    //checando se as datas sao validas
    if (verificaDataValida(dia1, mes1, ano1) == 1 && verificaDataValida(dia2, mes2, ano2) == 1) {
        //printando as datas por extenso
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
        //identificando data mais antiga
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) {
            printf("A primeira data eh mais antiga\n");
        }
        else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) {
            printf("As datas sao iguais\n");
        }
        else {
            printf("A segunda data eh mais antiga\n");
        }
        if (-1 < calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2) && calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2) < 10) {
            printf("A diferenca em dias entre as datas eh: 0%d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
        }
        else {
            printf("A diferenca em dias entre as datas eh: %d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
        }
    }
    else {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
}