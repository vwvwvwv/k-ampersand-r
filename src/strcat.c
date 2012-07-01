#include <stdio.h>

void strcat(char s[], char t[]);

main()
{
     char str1[] = "foo";
     char str2[] = "baz";

     printf("%s\n", str1);
     printf("%s\n", str2);

     strcat(str1, str2);
     printf("%s\n", str1);
}

void strcat(char *s, char *t)
{
     int i, j;

     for (i = 0; s[i] != '\0'; i++)
	  ;
     for (j = 0; t[j] != '\0'; j++)
	  s[i+j] = t[j];
     s[i+j] = '\0';
}
