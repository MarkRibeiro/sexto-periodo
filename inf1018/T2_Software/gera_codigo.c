#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int (*funcp) (int x);

void gera_codigo (FILE *f, void **code, funcp *entry)
{
	char v[100];

	for(;feof(f)!=1;fread(v, 1, 1, f))
	{
		fscanf(f,"%[^\n]", v);
		if(v[0]=='f') //function
		{
			printf("ok(f) ");
			code[0]=0x55;
			code[1]=0x48;
			code[2]=0x89;
			code[3]=0xe5;
			code[4]=0x48;
			code[5]=0x83;
			code[6]=0xec;
			code[7]=0x20;
		}
		if(v[0]=='c') //call
			printf("ok(c) ");

		if(v[0]=='z') //zret
			printf("ok(z) ");

		if(v[0]=='r') //ret
			printf("ok(r) ");

		if(v[0]=='e') //end
			printf("ok(e) ");

		if(v[3]=='=') //=
		{
			if(v[8]=='+') //+
				printf("ok(+) ");

			if(v[8]=='-') //-
				printf("ok(-) ");
			
			else //
				printf("ok(*) ");
		}
		printf("%p\n", code[0]);
	}
	/*
	code[3]=0xc745f864000000;
	code[4]=0x8b45f8;
	code[5]=0xc9;
	code[6]=0xc3;

	printf("%p", code[0]);
	printf("%p", code[1]);
	printf("%p", code[2]);
	printf("%p", code[3]);
	printf("%p", code[4]);
	printf("%p", code[5]);
	printf("%p", code[6]);
	printf("%p", code[7]);
	printf("%p", code[8]);
	printf("%p", code[9]);
	*/
}

void libera_codigo (void *p)
{
	
}
  
  
  
  
  
  