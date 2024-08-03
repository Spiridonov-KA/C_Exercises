#include <stdio.h>

int foo(int a) {
	return a * a;
}

int main() {
	int a = 10;
	int * const pa = &a;
	int (*pfoo)(int) = &foo;
	printf("address a = %p\n", pa);
	printf("address foo = %p\n", pfoo);
}
