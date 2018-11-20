#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int n) 
{
	int a = 0, l = 0, i=1;
	
	for (; *s; s++)
		a = a*10 + (*s - '0');

	switch(n)
	{
		case 2:
		{
  			for(;a/2!=0;a=a/2)
			{
				l=l + (a%2)*i;
				i=i*10;
			}
			l=l + a*i;
			return l;
		}
		case 8:
		{
			for(;a/8!=0;a=a/8)
			{
				l=l + (a%8)*i;
				i=i*10;
			}
			l=l + a*i;
			return l;
		}
		case 10:
		{
			return a;
		}
		case 16:
		{
			for(;a/16!=0;a=a/16)
			{
				l=l + (a%16)*i;
				i=i*10;
			}
			l=l + a*i;
			return l;
		}
	}
	return a;
}

int main (void) 
{
  	printf("B2 ==> %d\n", string2num("500", 2));
  	printf("B8 ==> %d\n", string2num("500", 8));
  	printf("B10 ==> %d\n", string2num("500", 10));
  	printf("B16 ==> %d\n", string2num("500", 16));
  	return 0;
}

