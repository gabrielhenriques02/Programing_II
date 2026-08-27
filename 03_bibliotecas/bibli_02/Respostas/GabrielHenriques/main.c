#include "matrix_utils.h"
#include <stdio.h>

int main() {
    int rows1, cols1;

    scanf("%i%i", &rows1, &cols1);

    int matrix1[rows1][cols1];

    matrix_read(rows1, cols1, matrix1);
    matrix_print(rows1, cols1, matrix1);
}