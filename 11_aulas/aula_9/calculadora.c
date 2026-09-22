#include <stdio.h>
#include "calculadora.h"

fptrOperacao operacoes[128] = {NULL};

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

void inicializa_array_operacoes() {
    operacoes['+'] = sum; // ‘+’ = 43
    operacoes['-'] = sub; // ‘-’ = 45
    operacoes['*'] = mult; // ‘*’ = ??
    operacoes['/'] = div; // ‘/’ = ??
}

int calculadora(char op_cod, int num1, int num2) {
    fptrOperacao op;
    op = operacoes[op_cod];
    return op(num1, num2);
}
