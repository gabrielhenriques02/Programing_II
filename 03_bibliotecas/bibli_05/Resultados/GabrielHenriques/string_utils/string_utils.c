#include <stdio.h>
#include "string_utils.h"

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    //inicializa o contador para o tamanho da string
    int stringLength = 0;
    //inicializa o contador para percorrer os caracteres no loop
    int charIndice = 0;
    //loop para iterar cada caractere da string.
    while (1) {
        if (str[charIndice] != '\0') {
            stringLength++;
            charIndice++;
            continue;
        }
        else {
            break;
        }
    }
    return stringLength;

}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    //loop para copiar os respectivos caracteres de src para dest
    for (int i = 0; i < string_length(src) + 1; i++) {
        dest[i] = src[i];
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    //verifica se o caractere eh uma letra minuscula, se sim, converte para maiuscula
    for (int i = 0; i < string_length(str); i++) {
        if (str[i] > 96 && str[i] < 125) {
            str[i] -= 32;
        }
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    //verifica se o caractere eh uma letra maiuscula, se sim, converte para minuscula
    for (int i = 0; i < string_length(str); i++) {
        if (str[i] > 64 && str[i] < 92) {
            str[i] += 32;
        }
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    //criando uma cópia de str para ser a "base do mapa" de inversão  de caracteres
    char copy[string_length(str) + 1];
    for (int i = 0; i < string_length(str) + 1; i++) {
        copy[i] = str[i];
    }
    //loop para inverter a ordem dos caracteres de str com base em copy
    for (int i = 0; i < string_length(str); i++) {
        str[i] = copy[string_length(str) - 1 - i];
    }
}