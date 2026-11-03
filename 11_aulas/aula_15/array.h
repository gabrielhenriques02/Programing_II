#ifndef _ARRAY_
#define _ARRAY_

typedef struct Array Array;

typedef void (*func_ptr_desaloca)(void *);
typedef void (*func_ptr_print)(void *);

Array *criaArray(func_ptr_desaloca desaloca);
void addElementoArray(Array *a, void *elem);
void *getElementoArray(Array *a, int pos);
int getTamArray(Array *a);
void printArray(Array *a, func_ptr_print printData);
void liberaArray(Array *a);

#endif