#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int main()                                                
{
    int vet[4];

    LeDadosParaVetor(vet, 4);
    ImprimeDadosDoVetor(vet, 4);

/*    for (int i = 0; i < 4; i++) {
        printf("idx %d: %d\n", i, vet[i]);
    }
    
    int casos; 

    scanf("%d", &casos); 
    while(casos){ 
        int tam; 
        scanf("%d", &tam); 
 
        int vet[tam]; 
        LeDadosParaVetor(vet, tam); 
 
        OrdeneCrescente(vet, tam); 
   
        ImprimeDadosDoVetor(vet, tam); 
   
        casos--; 
    }  
  
    return 0;
*/ 
} 