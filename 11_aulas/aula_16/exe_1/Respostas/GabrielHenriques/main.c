#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "histograma.h"

int main() {
    int nIntervalos;
    scanf("%d\n", &nIntervalos);
    Imagem *img = LerImagem();
    Histograma *h = CalcularHistograma(img, nIntervalos);
    //ImprimirImagem(img);
    qsort(ObterDadosImagem(img), getTamImagem(img), sizeof(float), comparaPixelsFloat);
    ImprimirImagem(img);
    MostrarHistograma(h);
    DestruirImagem(img);
    DestruirHistograma(h);
    

    return 0;
}