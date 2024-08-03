#include <stdio.h>
#include <stdlib.h>

typedef int MyInt;
typedef int * MyPInt;
typedef const int * MyPCInt;
typedef int *const MyCPInt;

typedef struct my_struct {
	int x, y, z;
} oppa;

typedef int myarr[5];

int foo(int);
int (*pfoo)(int);

int foo (int a) {
	return a * a;
}

typedef int (*pf)(const void *, const void *);

int intless(const void *lhs, const void *rhs) {
	const int *ilhs = (const int *) lhs;
	const int *irhs = (const int *) rhs;
	if (*ilhs >	*irhs) return 1;
	if (*ilhs <	*irhs) return -1;
	return 0;
}

int main() {
	int a = 10;
	const int b = 15;
	printf("b = %d\n", b);
	int const c = 20;
	const int *pcb = &b;
	int const *pca = &a;
	int * const cpb = &b;
	const int *const cpca = &b;
	MyInt ia = 100;
	oppa t;
	t.x = 10;
	myarr aa;
	printf("sizeof = %ld\n", sizeof(aa));
	printf("a = %d\n", ia);
	int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int (*parr3)[3];
	printf("parr3 = %ld\n", sizeof(*parr3));
	parr3 = arr;
	printf("parr3[0] = %d\n", (*parr3)[0]);
	parr3 += 1;
	printf("parr3[3] = %d\n", (*parr3)[0]);

	pfoo = &foo;
	printf("res = %d\n", pfoo(8));
	int array[10] = {89, 43, 18, 47, 82, 4, -2, 14, 23, 72};
	qsort(array, 10, sizeof(int), &intless);
	printf("%d\n", intless);
	printf("%d\n", &intless);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
