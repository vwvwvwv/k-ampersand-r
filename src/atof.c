/* doesn't work */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

double atof(char []);
// double pow(double, int);
int getaline(char s[], int lim);

/* rudimentary calculator */
main()
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (getaline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

/* atof:  convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exp, expsign;

	for (i = 0; isspace(s[i]); i++) /* skip whitespace */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	else if (s[i] == 'e' || s[i] == 'E') {
		i++;
		goto exponent;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power += 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		goto exponent;
	}

	return sign * val / power;

exponent:
	expsign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++) {
		exp = 10 * exp + (s[i] - '0');
	}

	return sign * val * pow(10, exp*expsign) / power; 
}

/*
double pow(double b, int p)
{
	double result;

	if (p > 0)
		for (result = 1.0; p > 0; --p)
			result *= b;
	else if (p < 0)
		for (result = 1.0; p < 0; ++p)
			result /= b;
	else
		result = 1.0;

	return result;
} */

int getaline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
