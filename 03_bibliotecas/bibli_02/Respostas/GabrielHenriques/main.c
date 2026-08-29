#include "matrix_utils.h"
#include <stdio.h>

int main() {

    //fluxo de início do programa.
    //definindo e arazenando os parametros para matriz 1.
    int rows1, cols1;
    scanf("%d%d", &rows1, &cols1);
    //definindo a matriz 1.
    int matrix1[rows1][cols1];
    //lendo a matriz 1.
    matrix_read(rows1, cols1, matrix1);

    //definindo e arazenando os parametros para matriz 2.
    int rows2, cols2;
    scanf("%d%d", &rows2, &cols2);
    //definindo a matriz 2.
    int matrix2[rows2][cols2];
    //lendo a matriz 2.
    matrix_read(rows2, cols2, matrix2);
    //fim do fluxo de início do programa.
/*
    //fluxo opcao 1 - somar matrizes
    //verifica se a soma é possível
    if (possible_matrix_sum(rows1, cols1, rows2, cols2) == 1) {
        //definindo matriz result.
        int result[rows1][cols1];
        //realiza a adicao e salva em result.
        matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        matrix_print(rows1, cols1, result);
    }
    else {
        //mensagem de erro se nao for possivel somar.
        printf("Erro: as dimensoes da matriz nao correspondem\n");
    }
    
    //fluxo opcao 2 - subtrair matrizes
    //verifica se a subtracao é possível
    if (possible_matrix_sub(rows1, cols1, rows2, cols2) == 1) {
        //definindo matriz result.
        int result[rows1][cols1];
        //realiza a subtracao e salva em result.
        matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        matrix_print(rows1, cols1, result);
    }
    else {
        //mensagem de erro se nao for possivel somar.
        printf("Erro: as dimensoes da matriz nao correspondem\n");
    }

    //fluxo opcao 3 - multiplicar matrizes
    if (possible_matrix_multiply(cols1, rows2) == 1) {
        //definindo a matriz resultado.
        int result[rows1][cols2];
        //realiza a multiplicação e armazena em result.
        matrix_multiply(rows1, cols1, matrix1, rows1, cols2, matrix2, result);
        matrix_print(rows1, cols2, result);
    }
    else {
        //mensagem de erro padrao.
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz");
    }

    //fluxo opcao 4 - multiplicacao de matriz por um escalar
    //inicializando o escalar e a escolha da matriz a ser operada.
    int scalar, matrixIndex;
    scanf("%i", &scalar);
    scanf("%i", &matrixIndex);

    //loop para operara a matriz escolhida.
    if (matrixIndex == 1) {
        scalar_multiply(rows1, cols1, matrix1, scalar);
        matrix_print(rows1, cols1, matrix1);
    }
    else {
        scalar_multiply(rows2, cols2, matrix2, scalar);
        matrix_print(rows2, cols2, matrix2);
    }
*/
    //fluxo opcao 5 - transposta de uma matriz
    //definindo o resultado das transposicoes.
    int result1[cols1][rows1], result2[cols2][rows2];

    //transpondo e printando a matriz1
    transpose_matrix(rows1, cols1, matrix1, result1);
    matrix_print(cols1, rows1, result1);

    //transpondo e printando a matriz2
    transpose_matrix(rows2, cols2, matrix2, result2);
    matrix_print(cols2, rows2, result2);

}