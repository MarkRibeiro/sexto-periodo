#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void cabecalho (int nstructs, char ord, char *campos, FILE *f)
{
	int strcamp = strlen(campos);
	int i=0;
	char c=0;
	fputc(nstructs, f);

	if(ord=='L')
	{
		strcamp = 0x00000080 | strcamp;
		//putc(0x00000001, f);
		fputc(strcamp, f);
	}
	else
	{
		strcamp = 0x00000000 | strcamp;
		fputc(strcamp, f);
	}
	
	for(i=0; campos[i]!='\0'; i++) //tá errado ainda, embora esteja printando certo
	{
		if(!(i%4))
			c = 0;
		if(campos[i]=='c')
		{
			char aux = 0x00;
			aux = aux<<(6-2*(i%4));
			c = c | aux;
		}

		if(campos[i]=='s')
		{
			char aux = 0x01;
			aux = aux<<(6-2*(i%4));
			c = c | aux;
		}
		
		if(campos[i]=='i')
		{
			char aux = 0x02;
			aux = aux<<(6-2*(i%4));
			c = c | aux;
		}
			
		if(campos[i]=='l')
		{
			char aux = 0x03;
			aux = aux<<(6-2*(i%4));
			c = c | aux;
		}
		
		if(i%4 == 3)
			fputc(c, f);
	}
	if(i%4)
		fputc(c, f);
}

int grava_structs (int nstructs, void *valores, char *campos, char ord, char *arquivo)
{
	FILE *f;
	unsigned char *val = (unsigned char*) valores;
	int i, tamMax = 0, by = 0;
	int j, byaux;
	int n = 0;
	f=fopen(arquivo, "wb");
	
	if(!f)
		return -1;
	
	cabecalho (nstructs, ord, campos, f);
	
	for(i=0; campos[i]!='\0'; i++)
	{
		int tam = 0;
		switch(campos[i])
		{
			case 'c':
				tam = 1;
				break;
			 case 's':
				tam = 2;
				break;
			case 'i':
				tam = 4;
				break;
			case 'l':
				tam = 8;
				break;
		}
		if(tam > tamMax)
			tamMax = tam;
	}
	i = 0;
	while(val)
	{
		if(campos[i]=='c')
		{
			fputc(*val, f);
			i++;
			if(campos[i]=='c')
			{
				val++;
				by++;
			}
			if(campos[i]=='s')
			{
				if(by%2==0)
				{
					val++;
					val++;
					by += 2;
				}
				else
				{
					val++;
					by++;
				}
			}
			if(campos[i]=='i')
			{
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%4; j++)
				{
					val++;
					by++;
				}
			}
			if(campos[i]=='l')
			{
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%8; j++)
				{
					val++;
					by++;
				}
			}
			if(campos[i]=='\0')
			{
				i = 0;
				n++;
				if(n == nstructs)
					break;
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%tamMax; j++)
				{
					val++;
					by++;
				}
			}
		}
		else if(campos[i]=='s')
		{
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			i++;
			if(campos[i]=='c')
			{
				val++;
				by++;
			}
			if(campos[i]=='s')
			{
				val++;
				by ++;
			}
			if(campos[i]=='i')
			{
				if((by+1)%4==0)
				{
					val++;
					by++;
				}
				else
				{
					val++;
					val++;
					val++;
					by += 3;
				}
			}
			if(campos[i]=='l')
			{
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%8; j++)
				{
					val++;
					by++;
				}
			}
			if(campos[i]=='\0')
			{
				i = 0;
				n++;
				if(n == nstructs)
					break;
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%tamMax; j++)
				{
					val++;
					by++;
				}
			}
		}
		else if(campos[i]=='i')
		{
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			i++;
			if(campos[i]=='c')
			{
				val++;
				by++;
			}
			if(campos[i]=='s')
			{
				val++;
				by ++;
			}
			if(campos[i]=='i')
			{
				val++;
				by ++;
			}
			if(campos[i]=='l')
			{
				if((by+1)%8==0)
				{
					val++;
					by++;
				}
				else
				{
					val++;
					val++;
					val++;
					val++;
					val++;
					by += 5;
				}
			}
			if(campos[i]=='\0')
			{
				i = 0;
				n++;
				if(n == nstructs)
					break;
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%tamMax; j++)
				{
					val++;
					by++;
				}
			}
		}
		else if(campos[i]=='l')
		{
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			val++;
			by++;
			fputc(*val, f);
			i++;
			if(campos[i]=='c')
			{
				val++;
				by++;
			}
			if(campos[i]=='s')
			{
				val++;
				by ++;
			}
			if(campos[i]=='i')
			{
				val++;
				by ++;
			}
			if(campos[i]=='l')
			{
				val++;
				by ++;
			}
			if(campos[i]=='\0')
			{	
				i = 0;
				n++;
				if(n == nstructs)
					break;
				val++;
				by++;
				byaux = by;
			
				for(j=0; j<byaux%tamMax; j++)
				{
					val++;
					by++;
				}
			}
		}
	}
	
	fclose(f);
	return 0;
}

void pegaCampos(int ncampos, FILE *f, unsigned char *campos, unsigned char *v)
{
	int i;

	fread(v, 1, 1, f);

	for(i=0;i<ncampos;i++)
	{
		
		switch(*v & 0xc0)
		{
			case 0x00:
				campos[i]='c';
				break;

			case 0x40:
				campos[i]='s';
				break;

			case 0x80:
				campos[i]='i';
				break;

			case 0xc0:
				campos[i]='l';
				break;
		}
		*v<<=2;
		if((i+1)%4==0)
			fread(v,1,1,f);
	}
}

void dump_structs (char *arquivo)
{
	unsigned char v[1], ord, *campos;
	int nstructs , ncampos, rep=0;
	int i, j, k;
	FILE *f = fopen(arquivo, "rb");

	if(f==NULL)
	{
		printf("Erro na Abertura do arquivo\n");
		exit(1);
	}
	/*---- lendo o numero de structs ----*/
	fread(v, 1, 1, f);
	nstructs = *v;
	
	/*---- lendo a ordenacao e o numero de campos ----*/
	fread(v, 1, 1, f);
	ord = *v & 0x80;       // 84 -> 1000 0000 
	ncampos = *v & 0x7f;

	campos = (unsigned char*) malloc (ncampos * sizeof(unsigned char));
	if(campos==NULL)
	{
		printf("Memoria insuficiente\n");
		exit(1);
	}

	pegaCampos(ncampos, f, campos, v);
  
	if (ord==0) 
		ord = 'B';
	else 
		ord = 'L';

	printf("%c\n", ord);
	printf("%d\n", nstructs);

	for(i=0;i<nstructs;i++)
	{
		j=0;
		printf("*\n");

		for(j=0;j<ncampos;j++)
		{
			switch (campos[j])
			{
				case 'c':
					rep = 1;
					break;

				case 's':
					rep = 2;
					break;

				case 'i': 
					rep = 4;
					break;

				case 'l': 
					rep = 8;
					break;
			}

			for(k=0;k<rep;k++)
			{
				fread(v, 1, 1, f);
				printf("%02x ", *v);
			}
			printf("\n");
		}
	}
	free(campos);
	fclose(f);
}
