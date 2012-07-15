#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	char teststr[] = "Hello, world!\n";
	squeeze(teststr, "Hl!");
	printf("%s", teststr);
}

/* squeeze:  delete each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int hasc = 0; /* does it contain the character? */

	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) 
			if (s1[i] == s2[j])
				hasc = 1;
		if (hasc == 0) 
			s1[k++] = s1[i];
		hasc = 0;
	}
	s1[k] = '\0';
}
