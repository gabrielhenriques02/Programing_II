#include <stdio.h>
#include "temperature_conversor.h"

int main(){
    //inicializando variaveis do programa
    float temperature;
    char actualScale, wishedScale;

    scanf("%f", &temperature);
    scanf("%c%c", &actualScale, &wishedScale);

    printf("teste\ntemp: %f\nactual: %c\nwished: %c\n", temperature, actualScale, wishedScale);
    //resolver probrela do buffer
    //leitura teste1:
    //teste
    //temp: 25.000000
    //actual:  
    //wished: c
}