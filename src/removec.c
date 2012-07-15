#include <stdio.h>

#define IN  1
#define OUT 0

/* removes all c comments from a file */
main()
{
	int strstate = OUT; /* inside string? state */
	int comstate = OUT; /* inside comment? state */
	int c = '\0';

	while ((c = getchar()) != EOF) {
		if (!strstate && c=='/' && (c=getchar())!=EOF && c=='*') {
			/* checks if we are opening a comment */
			comstate = IN;
		} else if (comstate && c=='*' && (c=getchar())!=EOF && c=='/') {
			/* checks if we are closing a comment */
			comstate = OUT;
		} else if (strstate && c=='\\' && (c=getchar())!=EOF && c=='"') {
			/* checks if this is an escaped string */
			printf("\\\"");
		} else if (!comstate && c == '"') {
			/* checks if we are opening/closing a string */
			strstate = !strstate;
			putchar('"');
		} else if (!comstate && !strstate && c=='\'' &&
				   (c=getchar())!=EOF && c=='"') {
			/* found string character enclosed in '"', does nothing */
		} else if (!comstate) {
			/* otherwise, just print it if we are not in a comment */
			putchar(c);
		}
	}
}
