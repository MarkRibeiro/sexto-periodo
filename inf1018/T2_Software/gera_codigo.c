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

int ret(char c,  int idx0, int posi)
{
  unsigned char *p=(unsigned char*)&idx0;

	switch (c)
	{
		case '$':
		{
			codigo[posi]=0xb8;
			codigo[posi+1]=*p;
      p++;
			codigo[posi+2]=*p;
      p++;
			codigo[posi+3]=*p;
      p++;
			codigo[posi+4]=*p;
      p++;

			return 5;
		}	

		case 'v':
		{
      codigo[posi]=0x8b;
      codigo[posi+1]=0x45;

      switch (idx0)
      {
        case 0:// -8(%rbp)
        {
          codigo[posi+2]=0xf8;

          return 3;
        }

        case 1:// -12(%rbp)
        {
          codigo[posi+2]=0xf4;

          return 3;
        }

        case 2:// -16(%rbp)
        {
          codigo[posi+2]=0xf0;

          return 3;
        }

        case 3:// -20(%rbp)
        {
          codigo[posi+2]=0xec;

          return 3;
        }

        case 4:// -24(%rbp)
        {
          codigo[posi+2]=0xe8;

          return 3;
        }

      }
		}	

		case 'p':
		{
      codigo[posi]=0x8b;
      codigo[posi+1]=0x45;

      switch (idx0)
      {
        case 0:// -4(%rbp)
        {
          codigo[posi+2]=0xfc;

          return 3;
        }

        case 1:// -8(%rbp)
        {
          codigo[posi+2]=0xf8;

          return 3;
        }

        case 2:// -12(%rbp)
        {
          codigo[posi+2]=0xf4;

          return 3;
        }

        case 3:// -16(%rbp)
        {
          codigo[posi+2]=0xf0;

          return 3;
        }

        case 4:// -20(%rbp)
        {
          codigo[posi+2]=0xec;

          return 3;
        }

      }
		}	
	}
  return 0;
}

void gera_codigo (FILE *f, void **code, funcp *entry)
{
  int line = 1, posi=0;
  int  c;

	
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

				codigo[posi]=0x55;
				codigo[posi + 1]=0x48;
				codigo[posi + 2]=0x89;
				codigo[posi + 3]=0xe5;
				codigo[posi + 4]=0x48;
				codigo[posi + 5]=0x83;
				codigo[posi + 6]=0xec;
				codigo[posi + 7]=0x20;
				codigo[posi + 8]=0x89;
				codigo[posi + 9]=0x7d;
				codigo[posi + 10]=0xfc;
        		
				printf("function\n");
				posi=posi+11;
        break;
      }

      case 'e': //end
			{ 
        char c0;
        if (fscanf(f, "nd%c", &c0) != 1)
          error("comando invalido", line);
				
				codigo[posi]=0xc9;
				codigo[posi+1]=0xc3;
        
				printf("end\n");
				posi=posi+2;
        break;
      }

      case 'r': //retorno incondicional 	
			{  
        int idx0;
        char var0;
        if (fscanf(f, "et %c%d", &var0, &idx0) != 2) 
          error("comando invalido", line);
        
				posi=posi+ret(var0, idx0, posi);

				printf("ret %c%d\n", var0, idx0);
        break;
      }

      case 'z': //retorno condicional
			{  
        int idx0, idx1;
        char var0, var1;
        if (fscanf(f, "ret %c%d %c%d", &var0, &idx0, &var1, &idx1) != 4) 
          error("comando invalido", line);
        
				printf("zret %c%d %c%d\n", var0, idx0, var1, idx1);
        break;
      }
      
			case 'v': //atribuicao
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
        }

        break;
      }

      default: error("comando desconhecido", line);
    }

   	line ++;
    fscanf(f, " ");
  }
}