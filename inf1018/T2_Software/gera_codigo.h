#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*funcp) (int x);
unsigned char *codigo;
int gera_codigo (FILE *f, void **code, funcp *entry);
int libera_codigo (void *p);