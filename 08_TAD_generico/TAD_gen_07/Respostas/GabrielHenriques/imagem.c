#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct tImagem {
    int altura, largura;
    Tipo tipo;
    void *val;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img) {
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img) {
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img) {
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img) {
    return img->val;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
    Imagem *i = (Imagem *) calloc(1, sizeof(Imagem));
    i->altura = altura;
    i->largura = largura;
    i->tipo = tipo;
    i->val = NULL;
    return i;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem() {
    Imagem *img = (Imagem *) calloc(1, sizeof(Imagem));
    img->val = NULL;
    scanf("%d %d %d\n", &img->altura, &img->largura, &img->tipo);

    int totalPixels = img->altura * img->largura;

    if (img->tipo == INT) {
        img->val = (void*) realloc(img->val, totalPixels*sizeof(int));

        for (int i = 0; i < totalPixels; i++) {
            int temp;
            scanf("%d", &temp);
            ((int*)img->val)[i] = temp;
        }
    }
    else if (img->tipo == FLOAT) {
        img->val = (void*) realloc(img->val, totalPixels*sizeof(float));

        for (int i = 0; i < totalPixels; i++) {
            float temp;
            scanf("%f", &temp);
            ((float*)img->val)[i] = temp;
        }
    }

    return img;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img);

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img) {
    free(img->val);
    free(img);
}

int getTamImagem(Imagem *img) {
    return img->altura * img->largura;
}