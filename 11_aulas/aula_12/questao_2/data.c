#include <stdio.h>
#include "data.h"

Data criaData() {
    Data d = {0};
    return d;
}

Data getData(Data d) {
    scanf("%d/%d/%d", d.dia, d.mes, d.ano);
    return d;
}