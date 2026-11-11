#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encaminhamento.h"

struct _Encaminhamento {
    char especialidade[100];
    char nomePaciente[100];
    char nomeMedico[100];
    char motivo[100];
};

Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivo) {
    Encaminhamento *r = (Encaminhamento *) calloc(1, sizeof(Encaminhamento));
    strcpy(r->especialidade, especialidade);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->motivo, motivo);
    return r;
}

Encaminhamento *leEncaminhamento() {
    Encaminhamento *r = (Encaminhamento *) calloc(1, sizeof(Encaminhamento));
    scanf("%[^\n]\n", r->nomeMedico);
    scanf("%[^\n]\n", r->nomePaciente);
    scanf("%[^\n]\n", r->especialidade);
    scanf("%[^\n]\n", r->motivo);
    return r;
}

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere) {
    Encaminhamento *r = (Encaminhamento *) dado;
    int qtd = strlen(r->nomeMedico) + strlen(r->nomePaciente) + strlen(r->especialidade) + strlen(r->motivo);
    return qtd*precoCaractere;
}

void imprimeEncaminhamento(void *dado) {
    Encaminhamento *r = (Encaminhamento *) dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("ESPECIALIDADE: %s\n", r->especialidade);
    printf("MOTIVO: %s\n", r->motivo);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

void desalocaEncaminhamento(void *dado) {
    Encaminhamento *r = (Encaminhamento *) dado;
    free(r);
}