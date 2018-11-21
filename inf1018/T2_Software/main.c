#include<stdio.h>
#include"gera_codigo.h"

int main(int argc, char *argv[]) {
  FILE *fp;
  void *code;
  funcp funcSBF;

  /* Abre o arquivo para leitura */
  fp = fopen("sbf", "r");

  /* Gera o codigo */
  gera_codigo(fp, &code, &funcSBF);
  //if ((code == NULL) || (funcSBF == NULL)) 
  	//printf("Erro na geracao\n");

  /* Chama a função gerada */
  //res = (*funcSBF)(<argumento>);

  /* Libera a memória utilizada */
  //libera_codigo(code);

}
