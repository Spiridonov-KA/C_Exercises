#include <stdio.h>
#include <stdlib.h>

void find_pos(int n, int *l, int *r) {
	*l = -1;
	*r = -1;
	for (int k = 0; n > 0; n >>= 1, ++k) {
		if (*r == -1 && n & 1) {
			*r = k;
		}
		if (n == 1) {
			*l = k;
		}
	}
}

#if 0

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
#endif

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

int main() {
	int n, l, r;
	scanf("%d", &n);

	if (n) {
		find_pos(n, &l, &r);
		printf("%d %d", l, r);
	}
	else {
		printf("-1");
	}
}
