#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VALMAX 600
typedef int (*funcp) (int x);
unsigned char *codigo;

static void error (const char *msg, int line) 
{
  fprintf(stderr, "erro %s na linha %d\n", msg, line);
  exit(EXIT_FAILURE);
}

int operacao (char var1, int idx1, char op, char var2, int idx2, int posi)
{
  switch (var1)
  {
    case 'p':
    {
      codigo[posi++]=0x8b;
      codigo[posi++]=0x55;
      codigo[posi++]=0xe8;

      break;
    }

    case 'v':
    {
      codigo[posi++]=0x8b;
      codigo[posi++]=0x55;
      codigo[posi++]=0xfc -4* idx1;

      break;
    }

    case '$':
    {
      codigo[posi++]=0xba;
      codigo[posi++]=idx1 & 0xff;
      codigo[posi++]=(idx1 >> 8) & 0xff;
      codigo[posi++]=(idx1 >> 16) & 0xff;
      codigo[posi++]=(idx1 >> 24) & 0xff;

      break;
    }
  }

  switch (op)
  {
    case '+':
    {
      switch (var2)
      {
        case 'p':
        {
          codigo[posi++]=0x03;
          codigo[posi++]=0x55;
          codigo[posi++]=0xe8;

          break;
        }

        case 'v':
        {
          codigo[posi++]=0x03;
          codigo[posi++]=0x55;
          codigo[posi++]=0xfc -4* idx2;

          break;
        }

        case '$':
        {
          codigo[posi++]=0x81;
          codigo[posi++]=0xc2;
          codigo[posi++]=idx2 & 0xff;
          codigo[posi++]=(idx2 >> 8) & 0xff;
          codigo[posi++]=(idx2 >> 16) & 0xff;
          codigo[posi++]=(idx2 >> 24) & 0xff;

          break;
        }
      }
      break;
    }

    case '-':
    {
      switch (var2)
      {
        case 'p':
        {
          codigo[posi++]=0x2b;
          codigo[posi++]=0x55;
          codigo[posi++]=0xe8;

          break;
        }

        case 'v':
        {
          codigo[posi++]=0x2b;
          codigo[posi++]=0x55;
          codigo[posi++]=0xfc -4* idx2;

          break;
        }

        case '$':
        {
          codigo[posi++]=0x81;
          codigo[posi++]=0xea;
          codigo[posi++]=idx2 & 0xff;
          codigo[posi++]=(idx2 >> 8) & 0xff;
          codigo[posi++]=(idx2 >> 16) & 0xff;
          codigo[posi++]=(idx2 >> 24) & 0xff;

          break;
        }
      }
      break;
    }

    case '*':
    {
      switch (var2)
      {
        case 'p':
        {
          codigo[posi++]=0x0f;
          codigo[posi++]=0xaf;
          codigo[posi++]=0x55;
          codigo[posi++]=0xe8;

          break;
        }

        case 'v':
        {
          codigo[posi++]=0x0f;
          codigo[posi++]=0xaf;
          codigo[posi++]=0x55;
          codigo[posi++]=0xfc -4* idx2;

          break;
        }

        case '$':
        {
          codigo[posi++]=0x69;
          codigo[posi++]=0xd2;
          codigo[posi++]=idx2 & 0xff;
          codigo[posi++]=(idx2 >> 8) & 0xff;
          codigo[posi++]=(idx2 >> 16) & 0xff;
          codigo[posi++]=(idx2 >> 24) & 0xff;

          break;
        }
      }
      break;
    }
  }
  return posi;
}

int zret(char var0, int idx0, char var1, int idx1, int posi)
{
  switch (var0)
  {
    case '$':
    {
      
    } 

    case 'v':
    {
      switch (idx0)
      {
        case 0:// -8(%rbp)
        {
        
        }

        case 1:// -12(%rbp)
        {
        
        }

        case 2:// -16(%rbp)
        {
          
        }

        case 3:// -20(%rbp)
        {
          
        }

        case 4:// -24(%rbp)
        {
          
        }

      }
    } 

    case 'p':
    {

      
    } 
  }
  return 0;
}
int ret(char var0,  int idx0, int posi)
{
	switch (var0)
	{
		case '$':
		{
			codigo[posi++]=0xb8;
			codigo[posi++]=idx0 & 0xff;
			codigo[posi++]=(idx0 >> 8) & 0xff;
			codigo[posi++]=(idx0 >> 16) & 0xff;
			codigo[posi++]=(idx0 >> 24) & 0xff;

			return posi;
		}	

		case 'v':  
		{
			codigo[posi++]=0x8b;
			codigo[posi++]=0x45;

    		switch (idx0)
    		{
    			case 0:// -4(%rbp)
        		{
        			codigo[posi++]=0xfc;

					return posi;
        		}

        		case 1:// -8(%rbp)
        		{
					codigo[posi++]=0xf8;

					return posi;
        		}

        		case 2:// -12(%rbp)
        		{
        			codigo[posi++]=0xf4;

        			return posi;
        		}

        		case 3:// -16(%rbp)
        		{	
        			codigo[posi++]=0xf0;	

        			return posi;
        		}

        		case 4:// -20(%rbp)
        		{	
        			codigo[posi++]=0xec;

        			return posi;
        		}
        	}
        }	

		case 'p': 
		{
			codigo[posi++]=0x89;
			codigo[posi++]=0xf8;

			return posi;
		}	

	}
  exit(1);
}

int gera_codigo (FILE *f, void **code, funcp *entry)
{
  	int line = 1, posi=0; //numfunc=0;
  	int  c; //idfunc[50];

	codigo=(unsigned char*)malloc(VALMAX * sizeof(char));

  	while ((c = fgetc(f)) != EOF) 	
	{
    	switch (c) 
		{
      		case 'f': //function 	
			{ 
        		char c0;        		
				if (fscanf(f, "unction%c", &c0) != 1)
          			error("comando invalido", line);

		        //idfunc[numfunc++]=&codigo[posi];
				codigo[posi++]=0x55;
				codigo[posi++]=0x48;
				codigo[posi++]=0x89;
				codigo[posi++]=0xe5;
				codigo[posi++]=0x48;
				codigo[posi++]=0x83;
				codigo[posi++]=0xec;
				codigo[posi++]=0x20;
		        codigo[posi++]=0x89;
		        codigo[posi++]=0x7d;
		        codigo[posi++]=0xe8;

		        *entry = (funcp)(codigo);
        
				printf("function\n");
        		break;
      		}

      		case 'e': //end
			{ 
        		char c0;
        		if (fscanf(f, "nd%c", &c0) != 1)
					error("comando invalido", line);
				
				codigo[posi++]=0xc9;
				codigo[posi++]=0xc3;
        
				printf("end\n");
        		break;
      		}

      		case 'r': //retorno incondicional 	
			{  
        		int idx0;
        		char var0;
        		if (fscanf(f, "et %c%d", &var0, &idx0) != 2)
					error("comando invalido", line);

				posi=ret(var0, idx0, posi);

				printf("ret %c%d\n", var0, idx0);
        		break;
      		}

	      	case 'z': //retorno condicional
			{  
	        	int idx0, idx1;
	        	char var0, var1;
	        	if (fscanf(f, "ret %c%d %c%d", &var0, &idx0, &var1, &idx1) != 4) 
	          		error("comando invalido", line);

	        	posi=zret(var0, idx0, var1, idx1, posi);
	        
				printf("zret %c%d %c%d\n", var0, idx0, var1, idx1);
	        	break;
	      	}
      
			case 'v': //atribuicao NAO ESTA TERMINADA
			{  
        		int idx0;
        		char var0 = c, c0;
        		if (fscanf(f, "%d = %c",&idx0, &c0) != 2)
          			error("comando invalido",line);

        		if (c0 == 'c') //call	
				{ 
          			int fp, idx1;
          			char var1;
          			if (fscanf(f, "all %d %c%d\n", &fp, &var1, &idx1) != 3)
            			error("comando invalido",line);
          
					printf("%c%d = call %d %c%d\n",var0, idx0, fp, var1, idx1);
        		}

        		else //operacao aritmetica 	
				{ 
          			int idx1, idx2;
          			char var1 = c0, var2, op;
          			if (fscanf(f, "%d %c %c%d", &idx1, &op, &var2, &idx2) != 4)
            			error("comando invalido", line);
        
					printf("%c%d = %c%d %c %c%d\n", var0, idx0, var1, idx1, op, var2, idx2);

          			posi=operacao(var1, idx1, op, var2, idx2, posi);
        		}

			        codigo[posi++]=0x89;
			        codigo[posi++]=0x55;
			        codigo[posi++]=0xfc -4* idx0;
			        break;
      		}

      		default: error("comando desconhecido", line);
    	}

   		line ++;
    	fscanf(f, " ");
  	}
  	*code = (void*)codigo;
  	return posi;
}

void libera_codigo(void *code)
{
  free(code);
}

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

  //for(i=0;i<posi;i++)
    //printf("%x\n", codigo[i]);

  /* Chama a função gerada */
  res = (*funcSBF)(1);
  printf("%d\n", res);

  /* Libera a memória utilizada */
  libera_codigo(code);

  fclose(fp);

  return 0;
}