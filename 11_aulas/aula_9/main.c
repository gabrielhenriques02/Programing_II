#include <stdio.h>
#include "calculadora.h"

int main() {

    int num1, num2, resultado;
    char opCod;

    inicializa_array_operacoes();

    printf("Selecione uma operacao (+ , - , * , /): \n");
    scanf("%c\n", &opCod);

    printf("digite os os inteiros a serem operados: \n");
    scanf("%d,%d", &num1, &num2);

    printf("%d %c %d = %d\n", num1, opCod, num2, calculadora(opCod, num1, num2));
}