#include <stdio.h>

main()
{
	printf("should be 2: %d\n", any("Hello","lo"));
	printf("should be -1: %d\n", any("12345", "#$^&*()"));
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	}

	return -1;
}
