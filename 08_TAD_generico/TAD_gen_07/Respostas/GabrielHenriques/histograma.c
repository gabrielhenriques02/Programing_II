#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "histograma.h"

struct tHistograma {
    int *pixelsIntervalos;
    int nIntervalos, tamIntervalos;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
    Histograma *h = (Histograma*) calloc(1, sizeof(Histograma));
    h->nIntervalos = nIntervalos;
    h->pixelsIntervalos = (int *) calloc(1, h->nIntervalos*sizeof(int));

    h->tamIntervalos = ceil(256.0/h->nIntervalos);

    for (int i = 0; i < h->nIntervalos; i++) {
        int temp = 0;
        
        for (int j = 0; j < ObterAltura(img)*ObterLargura(img); j++) {
            if (ObterTipoImagem(img) == INT) {
                int *dado = (int*) ObterDadosImagem(img);
                if (dado[j] >= 0 + h->tamIntervalos*i && dado[j] < h->tamIntervalos*(i + 1)) {
                    temp++;
                }
            }
            else if (ObterTipoImagem(img) == FLOAT) {
                float *dado = (float*) ObterDadosImagem(img);
                if (dado[j]*255 >= 0 + h->tamIntervalos*i && dado[j]*255 < h->tamIntervalos*(i + 1)) {
                    temp++;
                }
            }
        }

        h->pixelsIntervalos[i] = temp;
    }

    return h;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma) {
    for (int i = 0; i < histograma->nIntervalos; i++) {
        printf("[%d, %d): %d\n", 0 + histograma->tamIntervalos*i, histograma->tamIntervalos*(i + 1), histograma->pixelsIntervalos[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma) {
    free(histograma->pixelsIntervalos);
    free(histograma);
}
