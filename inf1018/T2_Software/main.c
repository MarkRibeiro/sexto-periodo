#include<stdio.h>
#include"gera_codigo.h"

int main(int argc, char *argv[]) {
  FILE *fp;
  void *code;
  funcp funcSBF;
  int res;

  /* Abre o arquivo para leitura */
  fp = fopen("sbf", "r");

  /* Gera o codigo */
  gera_codigo(fp, &code, &funcSBF);
  funcSBF =(funcp)codigo;
  if ((code == NULL) || (funcSBF == NULL)) 
  	printf("Erro na geracao\n");

  /* Chama a função gerada */
  res = (*funcSBF)(1);
  printf("%d\n", res);

  /* Libera a memória utilizada */
  //libera_codigo(code);

}
