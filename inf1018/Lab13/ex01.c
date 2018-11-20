#include<stdio.h>
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

union U
{
	unsigned int i;
	float f;
};

float float2 (float f)
{
	union U x;
	unsigned int u1;


	x.f = f1;
	u1 = u.i;
}

int main (void)
{
	float f1=0.65;

	

	printf("%f\n", float2(f1));
	return 0;
}