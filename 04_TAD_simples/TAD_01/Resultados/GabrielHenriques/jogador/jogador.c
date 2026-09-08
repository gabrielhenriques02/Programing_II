#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    while (1) {
        printf("Jogador %d\n", jogador.id);
        //cria a jogada
        tJogada jogada = LeJogada();
        //verifica se a jogada foi bem sucedida
        if (FoiJogadaBemSucedida(jogada) == 1) {
            if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1) {
                if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1) {
                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    return MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
                else {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    continue;
                }
            }
            else {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                continue;
            }
        }
    }            
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    
    if (jogador.id == 1) {
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            int countI = 0, countJ = 0, countDiagPrinc = 0, countDiagSec = 0;
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1) { //verificando se preencheu uma linha
                    countI++;
                    if (countI == 3) {
                        return 1;
                    }
                }
                else if (tabuleiro.posicoes[j][i] == tabuleiro.peca1) { //verificando se preencheu uma coluna
                    countJ++;
                    if (countJ == 3) {
                        return 1;
                    }
                }
                else if (tabuleiro.posicoes[j][j] == tabuleiro.peca1) { //verificando a diagonal principal
                    countDiagPrinc++;
                    if (countDiagPrinc == 3) {
                        return 1;
                    }
                }
                else if (tabuleiro.posicoes[j][TAM_TABULEIRO - 1 - j] == tabuleiro.peca1) { //verificando diagonal secundaria
                    countDiagSec++;
                    if (countDiagSec == 3) {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
    else {
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            int countI = 0, countJ = 0, countDiagPrinc = 0, countDiagSec = 0;
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                if (i % 3 == i && tabuleiro.posicoes[i][j] == tabuleiro.peca2) { //verificando se preencheu uma linha
                    countI++;
                    if (countI == 3) {
                        return 1;
                    }
                }
                else if (j % 3 == j && tabuleiro.posicoes[j][i] == tabuleiro.peca2) { //verificando se preencheu uma coluna
                    countJ++;
                    if (countJ == 3) {
                        return 1;
                    }
                }
                else if (tabuleiro.posicoes[j][j] == tabuleiro.peca2) { //verificando a diagonal principal
                    countDiagPrinc++;
                    if (countDiagPrinc == 3) {
                        return 1;
                    }
                }
                else if (tabuleiro.posicoes[j][TAM_TABULEIRO - 1 - j] == tabuleiro.peca2) { //verificando diagonal secundaria
                    countDiagSec++;
                    if (countDiagSec == 3) {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
}