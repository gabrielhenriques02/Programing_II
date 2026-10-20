#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

#define MAX_QTD_PACIENTES 100

int main() {
    Paciente *pacientes[MAX_QTD_PACIENTES];
    Data *dataBase = criaData(12, 9, 2023);
    int numPacientes = 0, sumIdades = 0, qtdLesoes = 0, qtdLesoesCirurgicas = 0;
    char opcao;

    while(scanf("%c\n", &opcao)) {
        if (opcao == 'P') {
            pacientes[numPacientes] = lerPaciente();
            numPacientes++;
        }
        else if (opcao == 'L') {
            Lesao *l = lerLesao();
            int lesaoVinculada = 0;
            for (int i = 0; i < numPacientes; i++) {
                if (strcmp(getCartaoSusPaciente(pacientes[i]), getCartaoSusLesao(l)) == 0) {
                    vinculaLesaoPaciente(pacientes[i], l);
                    lesaoVinculada = 1;
                }
            }
            if (!lesaoVinculada) {
                liberaLesao(l);
            }
            
        }
        else if (opcao == 'F') {
            break;
        }
    }

    for (int i = 0; i < numPacientes; i++) {
        sumIdades += calculaIdadePaciente(pacientes[i], dataBase);
        qtdLesoes += getNumLesoesPaciente(pacientes[i]);
        qtdLesoesCirurgicas += qtdLesoesCirurgicasPaciente(pacientes[i]);
    }

    if (numPacientes != 0) {
        printf("TOTAL PACIENTES: %d\n", numPacientes);
        printf("MEDIA IDADE (ANOS): %d\n", sumIdades / numPacientes);
        printf("TOTAL LESOES: %d\n", qtdLesoes);
        printf("TOTAL CIRURGIAS: %d\n", qtdLesoesCirurgicas);
        printf("LISTA DE PACIENTES:\n");

        for (int i = 0; i < numPacientes; i++) {
            imprimePaciente(pacientes[i]);
        }

        for (int i = 0; i < numPacientes; i++) {
            liberaPaciente(pacientes[i]);
        }
    }
    else {
        printf("TOTAL PACIENTES: 0\n");
        printf("MEDIA IDADE (ANOS): -\n");
        printf("TOTAL LESOES: 0\n");
        printf("TOTAL CIRURGIAS: 0\n");
        printf("LISTA DE PACIENTES:\n");
    }

    liberaData(dataBase);

    return 0;
}