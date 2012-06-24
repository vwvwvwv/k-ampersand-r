#include <stdio.h>

void reverse(char s[]);

main()
{
	char s[] = "Hello, world!\n";
	printf("%s",s);
	reverse(s);
	printf("%s",s);
}

/* doesn't work (yet) */
void reverse(char s[])
{
	int i, j;
	char buffer[1000];

	for (i=0; s[i]!='\0'; ++i)
		;

	for (j=0; i>0 && j<999; --i, ++j)
		buffer[j] = s[i];
	buffer[++j] = '\0';

	for (i=0; buffer[i]!='\0'; ++i)
		s[i] = buffer[i]; 
}
