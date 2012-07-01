#include <stdio.h>

char *strncpy(char*, char*, int);
char *strncat(char*, char*, int);
int  strncmp(char*, char*, int);

main()
{
  char str1[30] = "Hello, world";
  char str2[30] = "qwertyuiop";
  char str3[30] = "Hello";

  printf("%s\n", strncpy(str2, str3, 3));
  printf("%s\n", strncpy(str2, str3, 9));
  printf("%s\n", strncat(str1, str2, 3));
}

char *strncpy(char *s, char *t, int n)
{
  int i;
  for (i = 0; i < n && t[i] != '\0'; i++)
    s[i] = t[i];
  if (t[i] == '\0')
    s[i] = '\0';

  return s;
}

char *strncat(char *s, char *ct, int n)
{
  int i, j;
  for (i = 0; s[i] != '\0'; i++)
    ;
  for (j = 0; ct[j] != '\0' && j < n; j++)
    s[i+j] = ct[j];
  s[i+j] = '\0';

  return s;
}

/* I don't understand what strncmp *really* is supposed to do,
   so here is a function that is like strend but at the beginning */
int strncmp(char *s, char *ct, int n)
{
  int i;
  for (i=0; i<n && s[i]!='\0' && ct[i]!='\0'; i++)
    if (s[i] != ct[i])
      return 0;
  return 1;
}
