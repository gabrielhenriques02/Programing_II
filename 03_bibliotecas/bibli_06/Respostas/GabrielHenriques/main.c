#include <stdio.h>
#include <string.h>
#include "temperature_conversor.h"

int main(){
    //inicializando variaveis do programa
    float temperature;
    char actualScale, wishedScale;
    //armazenando os dados do usuario nas variaveis
    scanf("%f %c %c", &temperature, &actualScale, &wishedScale);

    switch (actualScale) {
    case 'c': {
        switch (wishedScale) {
            case 'f': {
                printf("Temperature: %.2f%cº", convert_celsius_to_fahrenheit(temperature), 'f' - 32);
                break;
            }
            case 'k': {
                printf("Temperature: %.2f%c", convert_celsius_to_kelvin(temperature), 'k' - 32);
                break;
            }
            default: {
                break;
            }
        } 
        break;
    }
    case 'f': {
        switch (wishedScale){
        case 'c': {
            printf("Temperature: %.2f%cº", convert_fahrenheit_to_celsius(temperature), 'c' - 32);
            break;
        }
        case 'k': {
            printf("Temperature: %.2f%c", convert_fahrenheit_to_kelvin(temperature), 'k' - 32);
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    case 'k': {
        switch (wishedScale) {
            case 'c': {
                printf("Temperature: %.2f%cº", convert_kelvin_to_celsius(temperature), 'c' - 32);
                break;
            }
            case 'f': {
                printf("Temperature: %.2f%cº", convert_kelvin_to_fahrenheit(temperature), 'f' - 32);
                break;
            }
            default: {
                break;
            }
        }
        break;
    }
    default: {
        break;
    }
    }   
}