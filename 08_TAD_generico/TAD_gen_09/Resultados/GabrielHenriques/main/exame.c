#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

struct _Exame {
    char nomePaciente[100];
    char nomeMedico[100];
    char descricao[100];
};

Exame *criaExame(char *nomePaciente, char *nomeMedico, char *descricao) {
    Exame *r = (Exame *) calloc(1, sizeof(Exame));
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->descricao, descricao);
    return r;
}

Exame *leExame() {
    Exame *r = (Exame *) calloc(1, sizeof(Exame));
    scanf("%[^\n]\n", r->nomeMedico);
    scanf("%[^\n]\n", r->nomePaciente);
    scanf("%[^\n]\n", r->descricao);
    return r;
}

float calculaPrecoImpressaoExame(void *dado, float precoCaractere) {
    Exame *r = (Exame *) dado;
    int qtd = strlen(r->nomeMedico) + strlen(r->nomePaciente) + strlen(r->descricao);
    return qtd*precoCaractere;
}

void imprimeExame(void *dado) {
    Exame *r = (Exame *) dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("SOLICITACAO: %s\n", r->descricao);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - -\n");
}

void desalocaExame(void *dado) {
    Exame *r = (Exame *) dado;
    free(r);
}