#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*funcp) (int x);
unsigned char *codigo;
void gera_codigo (FILE *f, void **code, funcp *entry);
void libera_codigo (void *p);