#include <stdio.h>
int main(void) 
{
  	unsigned int x = 0x87654321;
  	unsigned int y, z, s;

  /* o byte menos significativo de x e os outros bits em 0 */
  	y = x & 0xff;

  /* o byte mais significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
	z = x | 0xff000000;

	s = x >> 4;

  	printf("y=%08x z=%08x x=%08x s=%08x\n", y, z, x, s);
}

// %x = imprime numero em hexadecimal
