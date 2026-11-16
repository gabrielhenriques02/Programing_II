#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

int main() {
    int nIntervalos;
    scanf("%d\n", &nIntervalos);
    Imagem *img = LerImagem();
    Histograma *h = CalcularHistograma(img, nIntervalos);
    MostrarHistograma(h);
    DestruirImagem(img);
    DestruirHistograma(h);

    return 0;
}