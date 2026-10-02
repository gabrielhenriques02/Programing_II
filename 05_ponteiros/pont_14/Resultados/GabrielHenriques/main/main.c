#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

typedef void (*funcBotao) (void);

void executaSalvar();
void executaExcluir();
void executaOpcoes();

int main() {
    //cria os atributos do programa
    Tela t, *pTela;
    Botao b1, b2, b3;
    funcBotao fptrB1, fptrB2, fptrB3;
    //inicializa o endereço dos ponteiros
    //pB1 = &b1;
    //pB2 = &b2;
    //pB3 = &b3;
    pTela = &t;
    fptrB1 = &executaSalvar;
    fptrB2 = &executaExcluir;
    fptrB3 = &executaOpcoes;
    //inicializa os botoes do framework
    b1 = CriarBotao("Salvar", 12, "FFF", 1, fptrB1);
    b2 = CriarBotao("Excluir", 18, "000", 1, fptrB2);
    b3 = CriarBotao("Opcoes", 10, "FF0000", 2, fptrB3);
    //inicializa a tela com os botoes
    t = CriarTela(400, 200);
    //registra botoes na tela
    RegistraBotaoTela(pTela, b1);
    RegistraBotaoTela(pTela, b2);
    RegistraBotaoTela(pTela, b3);
    //imprime a tela
    DesenhaTela(t);
    //espera o click
    OuvidorEventosTela(t);
    return 0;
}

void executaSalvar() {
    printf("- Botao de SALVAR dados ativado!\n");
}

void executaExcluir() {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void executaOpcoes() {
    printf("- Botao de OPCOES ativado!\n");
}