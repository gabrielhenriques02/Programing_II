#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    float* v = NULL, somaMedia = 0, somaDesv = 0, media = 0, desvPad = 0;
    int count = 0;

    while (1) {

        float num;
        
        scanf("%f\n", &num);

        if (num < 0) {
            break;
        }
        else {
            count++;
            v = realloc(v, count * sizeof(float));
            v[count - 1] = num;
        }
    }
    //teste se ta guardando direitinho
    for (int i = 0; i < count; i++) {
        printf("nota %d: %.2f\n", i + 1, v[i]);
    }
    //calcula soma das notas
    for (int i = 0; i < count; i++) {
        somaMedia += v[i];
    }
    //calcula media
    media = somaMedia / count;
    printf("media: %.2f\n", media);
    //calcula soma desv
    for (int i = 0; i < count; i++) {
        somaDesv += pow((v[i] - media), 2);
    }
    //calcula desvio padra
    desvPad = sqrt(somaDesv / count);
    printf("Desvio padrao: %.2f\n", desvPad);
}
