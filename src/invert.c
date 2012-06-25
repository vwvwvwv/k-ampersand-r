#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	printf("invert(0x%x,%d,%d) => 0x%x\n", 0x1284, 4, 4, invert(0x1284,4,4));
}

/* invert:  invert n bits at position p of x */
unsigned invert(unsigned x, int p, int n)
{
	unsigned mask = ~(~0 << n) << p;

	return ~(x & mask) & mask | (x & ~mask);
}
