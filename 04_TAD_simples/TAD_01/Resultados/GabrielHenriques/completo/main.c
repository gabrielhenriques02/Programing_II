#include <stdio.h>
#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"

int main() {
    
    while (1) {

        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
        if (!ContinuaJogo()) {
            break;
        }
        else {
            continue;
        }
    }
}