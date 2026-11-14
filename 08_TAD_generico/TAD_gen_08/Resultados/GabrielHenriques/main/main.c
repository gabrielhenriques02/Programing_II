#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "movel.h"

int main() {
    Fila *f = FilaConstruct();
    int qtdOp;
    scanf("%d\n", &qtdOp);

    while (qtdOp > 0) {
        char op[50];
        scanf("%s ",  op);

        if (strcmp(op, "ENTRADA") == 0) {
            tMovel *m = LeMovel();
            FilaPush(f, m);
        }
        else if (strcmp(op, "PRODUZIR") == 0) {
            tMovel *m = FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }

        qtdOp--;
    }

    FilaDestroy(f, DestroiMovel);

    return 0;
}