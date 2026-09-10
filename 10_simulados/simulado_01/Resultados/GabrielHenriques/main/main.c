#include <stdio.h>
#include "data.h"
#include "area.h"
#include "morador.h"
#include "reserva.h"

int main() {

    int qtdAreas, qtdMoradores, qtdReservas;
    Morador moradores[100];
    Area areas[10];
    Reserva reservas[100] = {0};

    scanf("%d\n", &qtdAreas);

    for (int i = 0; i < qtdAreas; i++) {
        areas[i] = lerArea();
    }

    scanf("%d\n", &qtdMoradores);

    for (int i = 0; i < qtdMoradores; i++) {
        moradores[i] = lerMorador();
    }

    scanf("%d\n", &qtdReservas);

    for (int i = 0; i < qtdReservas; i++) {

        char id[MAX_TAM_ID];
        char cpf[MAX_TAM_CPF];
        int qtdConvidados;
        int indexArea = 0, indexMorador = 0;

        scanf("%[^\n]\n", id);

        for (int j = 0; j < qtdAreas; j++) {
            if (verificaIdArea(areas[j], id)) {
                break;
            }
            else {
                indexArea++;
                continue;
            }
        }

        scanf("%[^\n]\n", cpf);

        for (int j = 0; j < qtdMoradores; j++) {
            if (verificaCPFMorador(moradores[j], cpf)) {
                break;
            }
            else {
                indexMorador++;
                continue;
            }
        }

        Data dRes = lerData();
        scanf("%d\n", &qtdConvidados);

        if (indexMorador < qtdMoradores && verificaSolicitacaoReserva(reservas, qtdReservas, moradores[indexMorador], areas[indexArea], dRes, qtdConvidados)) {
            reservas[i] = criaReserva(moradores[indexMorador], areas[indexArea], dRes, qtdConvidados);
            imprimeReserva(reservas[i]);
        }
        else {
            continue;
        }
    }
}