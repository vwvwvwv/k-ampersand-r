#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 10000     /* max #lines to be sorted */
char *lineptr[MAXLINES];   /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(char *lineptr[], int left, int right,
	       int (*comp)(void *, void *),
	       int reverse);
int numcmp(char *, char *);

char *alloc(int n);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines;  /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	int reverse = 0; /* 1 if reverse sort */
	int c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			default:
				printf("sort: illegal option %c\n", c);
				argc = 0;
				return 1;
				break;
			}
     
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		quicksort((void **) lineptr, 0, nlines-1,
			  (int (*)(void*,void*))(numeric ? numcmp : strcmp),
			  reverse);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int getln(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getln(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';  /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* getln:  read a line into s, return length */
int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* quicksort:  sort v[left]...v[right] into increasing order */
void quicksort(char *v[], int left, int right,
	       int (*comp)(void *, void *),
	       int reverse)
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)   /* do nothing if array contains */
		return;         /* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (!reverse) {
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		} else {
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
		}
 
	swap(v, left, last);
	quicksort(v, left, last-1, comp, reverse);
	quicksort(v, last+1, right, comp, reverse);
}

/* swap:  interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* numcmp:  compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else  /* not enough room */
		return 0;
}
