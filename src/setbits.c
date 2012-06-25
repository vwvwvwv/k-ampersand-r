#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

main()
{
	printf("--------\n%8x\n", setbits(0x1234321, 0x10, 0x8, 0xaaaaaa));
}

/*
 * setbits:  sets x with the n bits that begin at position p to the rightmost
 * n bits of y
 */
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
	/* ~(~0<<n) gives n ones on the right */
	unsigned xmask = ((~0<<n) << p) | ~(~0<<p);
	unsigned ymask = ~(~0<<n);
	printf("%8x\n", (~0<<n)); /* makes n zeros */
	printf("%8x\n", xmask); /* moves them over p spaces */
	printf("%8x\n", x&xmask);
	printf("%8x\n", y&ymask);
	printf("%8x\n", y&ymask << p);
	return (x&xmask) | (y&ymask << p);
}
