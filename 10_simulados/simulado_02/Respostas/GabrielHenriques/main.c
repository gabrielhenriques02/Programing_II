#include <stdio.h>
#include <stdlib.h>
#include "estacionamento.h"

int main() {
    Estacionamento *e = criaEstacionamento();
    char op;

    while (scanf("%c\n", &op) == 1) {
        if (op == 'E') {
            registraEntradaEstacionamento(e, lerVeiculo());
        }
        else if (op == 'S') {
            char placa[MAX_PLACA_VEIC];
            scanf("%[^\n]\n", placa);
            DataHora *saida = lerDataHora();
            if (registraSaidaEstacionamento(e, placa, saida) == 0) {
                liberaDataHora(saida);
            }
        }
        else if (op == 'F') {
            break;
        }
    }

    printf("TOTAL ENTRADAS: %d\n", getTotalEntradasEstacionamento(e));
    printf("TOTAL SAIDAS: %d\n", getTotalSaidasEstacionamento(e));
    if (getTotalSaidasEstacionamento(e) != 0) {
        printf("PERMANENCIA MEDIA (MIN): %d\n", calculaPermanenciaTotalEstacionamento(e)/getTotalSaidasEstacionamento(e));
    }
    else {
        printf("PERMANENCIA MEDIA (MIN): -\n");
    }
    printf("FATURAMENTO (R$): %d\n", calculaFaturamentoEstacionamento(e));
    printf("VEICULOS NO PATIO: %d\n", getTotalNoPatioEstacionamento(e));
    printf("LISTA DE VEICULOS NO PATIO:\n");
    imprimeVeiculosNoPatioEstacionamento(e);
    liberaEstacionamento(e);
    return 0;
}