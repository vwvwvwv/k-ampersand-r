#include <stdio.h>

int strend(char[], char[]);

main()
{
  printf("%d\n", strend("Hello, world", "world"));
  printf("%d\n", strend("asdf", "fdsa"));
  printf("%d\n", strend("qwer", "iuqwer"));
}

int strend(char s[], char t[])
{
  int bool, i, j;

  for (i = 0; s[i] != '\0'; i++)
    ;
  for (j = 0; t[j] != '\0'; j++)
    ;
  for ( ; i > 0 && j > 0; i--, j--)
    if (s[i] != t[j])
      return 0;
  return 1;
}
