#include <stdio.h>
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo() {
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {

    int contador = 0;
    tJogador jogadorAtual;
    tTabuleiro tabuleiroAtual = jogo.tabuleiro;

    while (1) {
        
        if (contador % 2 == 0) {
            jogadorAtual = jogo.jogador1;
        }
        else {
            jogadorAtual = jogo.jogador2;
        }

        tabuleiroAtual = JogaJogador(jogadorAtual, tabuleiroAtual);
        ImprimeTabuleiro(tabuleiroAtual);

        if (!VenceuJogador(jogadorAtual, tabuleiroAtual)) {
            contador++;
            continue;
        }
        else {
            printf("JOGADOR %d Venceu!\n", jogadorAtual.id);
            break;
        }
        if (!AcabouJogo(jogo)) {
            contador++;
            continue;
        }
        else {
            break;
        }
        
        contador++;
    }

    
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) {
    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 1;
    }
    else {
        return 0;
    }
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char option;
    printf("Jogar novamente? (s,n)\n");
    scanf(" %c", &option);
    if (option == 's') {
        return 1;
    }
    else {
        return 0;
    }
}