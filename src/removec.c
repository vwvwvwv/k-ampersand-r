#include <stdio.h>

#define IN  1
#define OUT 0

/* removes all c comments from a file */
main()
{
	int strstate; /* inside string? state */
	int comstate; /* inside comment? state */
	int c;

	strstate = comstate = OUT; /* begin out of comments and strings */
	
	while ((c = getchar()) != EOF) {
		if (!strstate && c=='/' && (c=getchar())!=EOF && c=='*') {
			/* checks if we are opening a comment */
			comstate = IN;
			// puts("setting comstate to IN");
		} else if (comstate && c=='*' && (c=getchar())!=EOF && c=='/') {
			/* checks if we are closing a comment */
			comstate = OUT;
			// puts("setting comstate to OUT");
		} else if (strstate && c=='\\' && (c=getchar())!=EOF && c=='"') {
			/* checks if this is an escaped string */
			printf("\\\"");
			// puts("found escaped string");
		} else if (!comstate && c == '"') {
			/* checks if we are opening/closing a string */
			strstate = !strstate;
			putchar('"');
			// puts("negating strstate");
		} else if (!comstate && !strstate && c=='\'' &&
				   (c=getchar())!=EOF && c=='"') {
			/* found string character enclosed in '"', does nothing */
			// printf("'\"");
		} else if (!comstate) {
			/* otherwise, just print it if we are not in a comment */
			putchar(c);
		}
	}
}
