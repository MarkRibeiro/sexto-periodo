#include"gera_codigo.h"

typedef int (*funcp) (int x);
unsigned char *codigo;
void gera_codigo (FILE *f, void **code, funcp *entry);
void libera_codigo (void *p);


int main(int argc, char *argv[]) 
{
  FILE *fp;
  void *code;
  funcp funcSBF;
  int res;

  /* Abre o arquivo para leitura */
  fp = fopen("sbf", "r");

  /* Gera o codigo */
  gera_codigo(fp, &code, &funcSBF);
  
  if ((code == NULL) || (funcSBF == NULL)) 
    printf("Erro na geracao\n");

  //for(i=0;i<posi;i++)
    //printf("%x ,", codigo[i]);
  //printf("\n");

  /* Chama a função gerada */
  res = (*funcSBF)(atoi(argv[2]));
  printf("%d\n", res);

  /* Libera a memória utilizada */
  libera_codigo(code);

  fclose(fp);

  return 0;
}