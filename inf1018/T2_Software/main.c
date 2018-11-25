#include"gera_codigo.h"

int main(void/*int argc, char *argv[]*/) 
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

  //for(i=0;i<posi;i++)
    //printf("%x\n", code[i]);

  /* Chama a função gerada */
  res = (*funcSBF)(1);
  printf("%d\n", res);

  /* Libera a memória utilizada */
  libera_codigo(code);

  fclose(fp);

  return 0;
}