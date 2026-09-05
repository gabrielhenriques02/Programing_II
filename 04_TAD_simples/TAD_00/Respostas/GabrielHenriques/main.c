#include <stdio.h>
#include "ponto.h"

int main() {
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("teste:\nx1: %f\ny1: %f\nx2: %f\ny2: %f\n", x1, y1, x2, y2);
    printf("%.3f", pto_distancia(pto_cria(x1, y1), pto_cria(x2, y2)));
}