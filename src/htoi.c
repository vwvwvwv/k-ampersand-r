#include <ctype.h>
#include <stdio.h>

/* converts a hexadecimal number in a string into an int */
main()
{
	char hex[] = "1f2c";

	printf("%s %d\n", hex, htoi(hex));
}

/* doesn't work for uppercase: too lazy */
int htoi(char s[])
{
	int i, n;
	
	n = 0;
	for (i = 0; isdigit(s[i]) || s[i] >= 'a' && s[i] <= 'f'; ++i) {
		if (isdigit(s[i]))
			n = 16 * n + (s[i] - '0');
		else
			n = 16 * n + (s[i] - 'a' + 10);
	}
	return n;
}
