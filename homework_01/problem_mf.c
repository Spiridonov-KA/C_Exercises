#include <stdio.h>
#include <stdlib.h>

#define N 4

void read_input(long long *x, int *n, int *m) {
	int res;
	for (int i = 0; i < N; ++i) {
		if (!scanf("%lld", &x[i])) {
			printf("Incorrenct input!\n");
			abort();
		}
	}
	res = scanf("%d%d", n, m);
	if (res != 2) {
		printf("Incorrenct input!\n");
		abort();
	}
}

void mult_mat(long long *a, long long *b, int m) {
	long long tmp1[N], tmp2[N];
	for (int i = 0; i < N; ++i) {
		tmp1[i] = a[i];
	}
	for (int i = 0; i < N; ++i) {
		tmp2[i] = b[i];
	}
	a[0] = ((tmp1[0] * tmp2[0]) % m + (tmp1[1] * tmp2[2]) % m) % m;
	a[1] = ((tmp1[0] * tmp2[1]) % m + (tmp1[1] * tmp2[3]) % m) % m;
	a[2] = ((tmp1[2] * tmp2[0]) % m + (tmp1[3] * tmp2[2]) % m) % m;
	a[3] = ((tmp1[2] * tmp2[1]) % m + (tmp1[3] * tmp2[3]) % m) % m;
}

void bpow_mat(long long *x, int n, int m) {
	long long prod[N];
	for (int i = 0; i < N; ++i) {
		prod[i] = x[i];
	}
	x[0] = 1;
	x[1] = 0;
	x[2] = 0;
	x[3] = 1;
	while (n) {
		if (n & 1) {
			mult_mat(x, prod, m);
		}
		mult_mat(prod, prod, m);
		n >>= 1;
	}
}

int main() {
	long long x[N];
	int n, m;
	read_input(x, &n, &m);

	bpow_mat(x, n, m);

	for (int i = 0; i < N; ++i) {
		printf("%lld ", x[i]);
	}
}
