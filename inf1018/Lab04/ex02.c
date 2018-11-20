#include <stdio.h>

void dump (void *p, int n) 
{
  	unsigned char *p1 = p;
  	while (n--) 
	{
    	printf("%p - %02x\n", p1, *p1);
    	p1++;
  	}
}

void altera(void *p)
{
	unsigned char *p1=p;
			
	*p1++=0x03;
	*p1++=0x80;
	*p1++=0xff;
	*p1=0xff;
	return;

}	

int main (void) 
{
  	short l = -32765;
  	unsigned short k = 32771;

	//altera(&k);
  	printf("l=%d, k=%u \n", l, k);
  	printf("dump de l: \n");

  	dump(&l, sizeof(l));

  	printf("dump de k: \n");
  
	dump(&k, sizeof(k));
  
	return 0;
}
