#ifndef _ARRAY_
#define _ARRAY_



typedef struct Array Array;

typedef void (func_ptr_adiciona) (void *dado);

Array *criaArray();

void adicionaElementoArray(Array *a, func_ptr_adiciona adiciona);


#endif