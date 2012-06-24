#include <stdio.h>
#include <math.h>

#define IN	1	/* inside word */
#define OUT	0	/* outside word */

#define max(A, B)	((A) > (B) ? (A) : (B))

/* displays a histogram of the lengths of words in input */
main()
{
	int wl[10]; /* word length */
	int c, i, state;
	int y, ymax, ystep;

	for (i = 0; i < 10; ++i)
		wl[i] = 0;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (i < 10)
				++wl[i];
			else 
				++wl[9];
		} else if (state == OUT) {
			i = 0;
			state = IN;
		} else {
			++i;
		}
	}

	printf("word lengths =");
	for (i = 0; i < 10; ++i)
		printf(" %d", wl[i]);
	printf("\n\n");

	/* get maximum */
	ymax = 0;
	for (i = 0; i < 10; ++i)
		ymax = max(ymax, wl[i]);
	
	if (ymax < 12)
		ystep = 1;
	else
		ystep = ymax/12;

	/* print table */
	for (y = 12; y > 0; --y) {
		printf("%3d: ", y*ystep);
		for (i = 0; i < 10; ++i) {
			if ((wl[i]/ystep - y) < 0 && y*ystep > wl[i]) {
				printf("  ");
			} else {
				printf(" #");
			}
		}
		printf("\n");
	}
	printf("     ");
	for (i = 0; i < 10; ++i)
		printf(" %d", i+1);
	printf("\n\n");
}
