#include <stdio.h>
#include <math.h>

#define IN	1	/* inside word */
#define OUT	0	/* outside word */

#define MAXWORDLEN 15  /* maximum word length recorded */
#define GRAPHHEIGHT 24 

#define max(A, B)	((A) > (B) ? (A) : (B))

/* displays a histogram of the lengths of words in input */
main()
{
	int wl[MAXWORDLEN]; /* word length */
	int c = '\0'; /* character buffer */
	int i = 0; /* iterator */
	int state = OUT; /* keeps track whether inside or outside a word */

	int y = 0; /* iterator for y axis */
	int ymax = 0; /* highest value for y axis */
	float ystep = 0; /* step for y axis */

	for (i = 0; i < MAXWORDLEN; ++i)
		/* initialize wl[] to 0 */
		wl[i] = 0;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			/* is there white space? if so, end the word */
			state = OUT;
			if (i < MAXWORDLEN)
				++wl[i];
			else if (i > 0)
				++wl[MAXWORDLEN-1];
		} else if (state == OUT) {
			/* there's a new word */
			i = 0;
			state = IN;
		} else {
			++i;
		}
	}

	printf("word lengths =");
	for (i = 0; i < MAXWORDLEN; ++i)
		printf(" %d", wl[i]);
	printf("\n\n");

	/* get maximum */
	ymax = 0;
	for (i = 0; i < 10; ++i)
		ymax = max(ymax, wl[i]);
	
	if (ymax < GRAPHHEIGHT)
		ystep = 1.0;
	else
		ystep = ymax * 1.0/GRAPHHEIGHT;

	/* print table */
	for (y = GRAPHHEIGHT; y > 0; --y) {
		printf("%4.0f", y*ystep);
		for (i = 0; i < MAXWORDLEN; ++i) {
			if ((wl[i]/ystep - y) < 0 && y*ystep > wl[i]) {
				printf("   ");
			} else {
				printf("  #");
			}
		}
		printf("\n");
	}
	printf("    ");
	for (i = 0; i < MAXWORDLEN; ++i)
		printf(" %2d", i+1);
	printf("+\n\n");
}
