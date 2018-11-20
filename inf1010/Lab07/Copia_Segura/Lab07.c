#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 17
int v[17];
void criaArquivo(int nPlacas)
{
	FILE *f = fopen("placas.txt", "w");
	int i;

	srand(time(NULL));

	for(i=0;i<nPlacas;i++)
		fprintf(f, "%c%c%c%c%c%c%c \n" , 'A' + rand()%26, 'A' + rand()%26, 'A' + rand()%26, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10);
	
	fclose(f);
}
void hash(int tamanho)
{
	int posi, i;
	int numeros[8]={19, 38, 64, 100, 81, 47, 27, 31};

	for(i=0;i<8;i++)
	{
		posi = numeros[i]%tamanho;

		JUMP:
		if(v[posi]!=0)
		{
			posi++;
			if(posi>=tamanho)
				posi=0;
			goto JUMP;
		}	
		else
			v[posi]=numeros[i];
	}
}

int main (void)
{
	int i;

	criaArquivo(1000);
	hash(SIZE);


	for(i=0;i<SIZE;i++)
		printf("v[%d]=%d\n", i, v[i]);

	return 0;

}