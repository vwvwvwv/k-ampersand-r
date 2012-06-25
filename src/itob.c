#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
	char s[100];

	printf("decimal: %d\n", -183);
	itob(-183, s, 2);
	printf("binary:  %s\n", s);
	itob(-183, s, 16);
	printf("hex:     %s\n", s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itob:  convert n to base b into string s[] */
void itob(int n, char s[], int b)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		if (n % b < 10)
			s[i++] = n % b + '0';
		else
			s[i++] = n % b + 'a' - 10;
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
