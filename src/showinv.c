#include <stdio.h>

/* prints input with invisible characters visible */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			printf("\\n\n");
		else if (c == '\t')
			printf("\\t");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
