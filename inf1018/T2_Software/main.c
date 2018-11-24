#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "gera_codigo.h"

unsigned char *codigo;

int main(int argc, char *argv[]) 
{
  FILE *fp;
  void *code;
  funcp funcSBF;
  int res, i, posi;

  /* Abre o arquivo para leitura */
  fp = fopen("sbf", "r");

  /* Gera o codigo */
  posi=gera_codigo(fp, &code, &funcSBF);
  
  if ((code == NULL) || (funcSBF == NULL)) 
    printf("Erro na geracao\n");

  for(i=0;i<posi;i++)
    printf("%x\n", codigo[i]);

  /* Chama a função gerada */
  res = (*funcSBF)(1);
  printf("%d\n", res);

  /* Libera a memória utilizada */
  libera_codigo(code);

  fclose(fp);

  return 0;
}