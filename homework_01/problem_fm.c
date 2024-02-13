#include <stdio.h>
#include <stdlib.h>

void read_input(int *n, int *m) {
	int res;
	res = scanf("%d%d", n, m);
	if (res != 2) {
		printf("Incorrect input!\n");
		abort();
	}
}

int fib_by_mod(int n, int m) {
	int prev = 0, cur = 1, tmp;
	if (n == 0) {
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		tmp = cur;
		cur = (prev + cur) % m;
		prev = tmp;
	}
	return cur;
}

int main() {
	int n, m, res;
	read_input(&n, &m);
	res = fib_by_mod(n, m);
	printf("%d", res);
}
