#include <stdio.h>
struct X {
  short s1;
  int i;
  char c[3];
  short s2;
} x= {0xa1, 0xa2, 0xa3};

void dump (void *p, int n) 
{
  	unsigned char *p1 = p;
  	
	while (n--) 
	{
    	printf("%p - %02x\n", p1, *p1);
    	p1++;
  	}
}

int main (void) 
{


  	printf ("x: \n");
  	dump (&x, sizeof(struct X));

  	return 0;
}
