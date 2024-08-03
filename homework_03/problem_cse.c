#if 0
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

void swap(char *a, char *b, int elem_size);

int compint(void const * lhs, void const * rhs) {
	const int* ilhs = (const int *) lhs;
	const int* irhs = (const int *) rhs;
	if (*ilhs < *irhs) return 1;
	return 0;
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp);

int main() {
	int n = 10;
	// int arr[10] = {10, 8, 7, 2, 8, 9, 15, 2, 9, 33};
	int arr[10] = {1, 2, 3, 4, 5, 8, 15, 6, 9, 33};
	// swap((char *)&arr[0], (char *)&arr[1], sizeof(int));
	selstep(arr, sizeof(int), n, 5, compint);
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
}

#endif

void swap(char *a, char *b, int elem_size) {
	char tmp;
	for (int i = 0; i < elem_size; ++i) {
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
	void *pmin;
	pmin = parr + nsorted * eltsize;
	for (int i = (nsorted + 1) * eltsize; i < numelts * eltsize; i += eltsize) {
		if (cmp(parr + i, pmin) == 1) {
			pmin = parr + i;
		}
	}
	swap(parr + nsorted * eltsize, pmin, eltsize);
	return 0;
}
