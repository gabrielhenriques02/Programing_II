#ifndef _CALCULADORA_H_
#define _CALCULADORA_H_

typedef int (*fptrOperacao) (int, int);

int sum(int a, int b);

int sub(int a, int b);

int mult(int a, int b);

int div(int a, int b);

void inicializa_array_operacoes();

int calculadora(char op_cod, int num1, int num2);

#endif