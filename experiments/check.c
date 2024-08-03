#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	int a, b, p, q, r, res;
	printf("input a and b: ");
	res = scanf("%d%d", &a, &b);
	printf("a / b = %d\n", a / b);
	printf("a %% b = %d\n", a % b);
	assert(a == (a / b) * b + (a % b));
	printf("%d\n", 1 / 0);
}
