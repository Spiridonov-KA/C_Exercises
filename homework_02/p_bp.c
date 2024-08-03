#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void read_input(int *n) {
	int res;
	res = scanf("%d", n);
	if (res != 1) {
		printf("Incorrect input\n");
		abort();
	}
}

void find_bits(int n, int *first, int *second) {
	int res = 0;
	if (n == 0) {
		*first = -1;
		*second = -1;
		return;
	}

	while (!(n & 1)) {
		n >>= 1;
		++res;
	}
	*first = res;

	while (n > 1) {
		n >>= 1;
		++res;
	}
	*second = res;
}

int main() {
	int n;
	int first, second;
	read_input(&n);

	find_bits(n, &first, &second);
	
	if (first == -1) {
		printf("%d", first);
	}
	else {
		printf("%d %d", second, first);
	}
}
