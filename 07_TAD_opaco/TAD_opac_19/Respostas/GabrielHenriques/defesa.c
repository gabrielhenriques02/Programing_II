#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defesa.h"

struct defesa {
    char *nome;
    float x, y, projecao, poder;
    int qtdMisseis;
    char tipo;
};

float calculaDistancia(float xDefesa, float yDefesa, float xAtaque, float yAtaque) {
    return sqrt(pow((xDefesa - xAtaque), 2) + pow((yDefesa - yAtaque), 2));
}

float calculaLado(float projecao) {
    return (2 * projecao) / sqrt(2);
}

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa() {
    tDefesa d = (tDefesa) calloc(1, sizeof(struct defesa));
    d->nome = (char *) calloc(MAX_TAM, sizeof(char));
    scanf("%s %f %f %c %f %f %d\n", d->nome, &d->x, &d->y, &d->tipo, &d->projecao, &d->poder, &d->qtdMisseis);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa) {
    printf("D-%s: %d\n", defesa->nome, defesa->qtdMisseis);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa) {
    free(defesa->nome);
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y) {
    if (defesa->tipo == 'Q') {
        float lado = calculaLado(defesa->projecao);
        if ((x < defesa->x + lado/2) && (x > defesa->x - lado/2) && (y < defesa->y + lado/2) && (y > defesa->y - lado/2)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (calculaDistancia(defesa->x, defesa->y, x, y) <= defesa->projecao) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa) {
    defesa->qtdMisseis--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa) {
    return defesa->poder;
}

/**
 * @brief Verifica se a defesa pode defender.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa) {
    if (defesa->qtdMisseis > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

