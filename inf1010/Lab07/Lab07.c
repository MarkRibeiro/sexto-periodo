#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 1300
char v[SIZE][8];

void criaVetor(void)
{
	int i;

	for(i=0;i<SIZE;i++)
		*v[i] = -1;
}
void criaArquivo(int nPlacas)
{
	FILE *f = fopen("placas.txt", "w");
	int i;

	srand(time(NULL));

	for(i=0;i<nPlacas;i++)
		fprintf(f, "%c%c%c%c%c%c%c \n" , 'A' + rand()%26, 'A' + rand()%26, 'A' + rand()%26, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10);
	
	fclose(f);
}
int hash(int tamanho)
{
	int posi, i, numero, coli=0;
	FILE *f = fopen("placas.txt", "r");
	char p[7];

	for(i=0;i<1000;i++)
	{
		fscanf(f, "%s\n", p);
		numero=p[0] + p[1] + p[2] + (p[3] - '0')*1000 + (p[4] - '0')*100 + (p[5] - '0')*10 + (p[6] - '0');
		posi = numero%tamanho;

		JUMP:
		if(*v[posi]!= -1)
		{
			coli++;
			posi++;
			if(posi>=tamanho)
				posi=0;
			goto JUMP;
		}	
		else
			strcpy(v[posi], p);
	}
	fclose(f);

	return coli;
}

int main (void)
{
	int i, coli=0;
	clock_t t[2];
	double tempo;

	criaVetor();
	criaArquivo(1000);

	t[0]=clock();
	coli=hash(SIZE);
	t[1]=clock();

	tempo=(t[1] - t[0]) * 1000.0/CLOCKS_PER_SEC;

	for(i=0;i<SIZE;i++)
		printf("v[%d]=%s\n", i, v[i]);
	printf("Tempo gasto: %g ms\nColisões: %d\n", tempo, coli);

	return 0;

}