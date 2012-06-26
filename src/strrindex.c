#include <stdio.h>

int strrindex(char s[], char t[]);

main()
{
	printf("%d\n", strrindex("Hello Hello Hello\n", "Hello"));
}

/* strrindex:  returns the position of the rightmost occurrence of t in s */
int strrindex(char s[], char t[])
{
	int i, j, k, last;

	last = -1;  /* if unfound */
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			last = i;
	}

	return last;
}
