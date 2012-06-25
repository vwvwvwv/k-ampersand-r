#include <stdio.h>

void escape(char s[], char t[]);

main()
{
	char s[] = "\t\tHello,\n\t\t\tworld!\n";
	char t[100];

	printf("%s\n", s);

	escape(s, t);

	printf("%s\n", t);
}

/* escape:  copies s to t with escape sequences */
void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i) {
		switch(s[i]) {
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	} 
	t[j] = '\0';
}
