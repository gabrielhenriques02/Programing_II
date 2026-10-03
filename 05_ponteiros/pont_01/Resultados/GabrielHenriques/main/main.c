#include <stdio.h> 
#include <stdlib.h> 
#include "utils.h"
 
//Defina e implemente TrocaInterios 
 
int main(){ 
    int n1, n2;
    int *pN1 = &n1, *pN2 = &n2;
   
    while ( scanf("%d %d", &n1, &n2) == 2 ){ 
        if ( TrocaInterios(pN1, pN2) ){ 
            printf("TROCADO: %d %d\n", n1, n2);
        } else {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }

    return 0;     
} 