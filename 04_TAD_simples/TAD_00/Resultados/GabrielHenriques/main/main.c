#include <stdio.h>
#include <math.h>
#include "ponto.h"

int main() {
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    if (floor(pto_distancia(pto_cria(x1, y1), pto_cria(x2, y2))) == pto_distancia(pto_cria(x1, y1), pto_cria(x2, y2))) {
        printf("%.f", pto_distancia(pto_cria(x1, y1), pto_cria(x2, y2)));
    }
    else {
        printf("%.3f", pto_distancia(pto_cria(x1, y1), pto_cria(x2, y2)));
    }
}