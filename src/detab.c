#include <stdio.h>

#define TABSTOP 4   /* number of spaces for each tab */

main()
{
	int c, i;

	i = 0;
	while((c = getchar()) != EOF) {
		if (c == '\t') {
			for ( ; i<TABSTOP; ++i)
				putchar(' ');
		} else {
			putchar(c);
			i = (++i) % TABSTOP;
		}
	}

	return 0;
}
