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

    //fluxo opcao 1 - somar matrizes:
    //verifica se a soma é possível
    if (possible_matrix_sum(rows1, cols1, rows2, cols2) == 1) {
        //definindo matriz result.
        int result[rows1][cols1];
        //realiza a adicao e salva em result.
        matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    }
    else {
        //mensagem de erro se nao for possivel somar.
        printf("Erro: as dimensoes da matriz nao correspondem\n");
    }
    
    //fluxo opcao 2 - subtrair matrizes:
    //verifica se a subtracao é possível
    if (possible_matrix_sub(rows1, cols1, rows2, cols2) == 1) {
        //definindo matriz result.
        int result[rows1][cols1];
        //realiza a subtracao e salva em result.
        matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    }
    else {
        //mensagem de erro se nao for possivel somar.
        printf("Erro: as dimensoes da matriz nao correspondem\n");
    }

    //inicio testes.
    //Precisa testar matrix_add e matrix_sub!!
    
    //fim testes.
}