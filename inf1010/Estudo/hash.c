#include<stdio.h>
#include<stdlib.h>
int main (void)
{
	int *v, tamanho=17, posi, i;
	int numeros[8]={19, 38, 64, 100, 81, 47, 27, 31};

	v = (int*)malloc(tamanho * sizeof(int));

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

	for(i=0;i<17;i++)
		printf("v[%d]=%d\n", i, v[i]);

	free(v);
	return 0;
}