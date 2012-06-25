#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);

main()
{
	int arr[100000];
	int i;

	for (i = 0; i < 100000; ++i)
		arr[i] = rand();

	printf("%d\n", binsearch(arr[124], arr, 100000));
}

/* binsearch:  original K&R version */
/* I believe it doesn't work */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;  /* no match */
}
