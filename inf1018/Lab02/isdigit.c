#include <stdio.h>
#include <ctype.h>
int string2num (char *s, int n) 
{
	int a=0;

	while(*s)
	{	
		if(isdigit(*s))
			a = a*n + (*s - '0');
		else
			a = a*n + (*s - 'a'+10);
		s++;
	}
	return a;
}
int main ()
{
	printf("B2 ==> %d\n", string2num("11001", 2));
  	printf("B8 ==> %d\n", string2num("500", 8));
  	printf("B10 ==> %d\n", string2num("500", 10));
  	printf("B16 ==> %d\n", string2num("2a", 16));
	printf("B32 ==> %d\n", string2num("2a", 32));

  	return 0;
}
