#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void read_input(unsigned long long *n) {
	int res;
	res = scanf("%lld", n);
	if (res != 1) {
		printf("Incorrect input!\n");
		abort();
	}
}

unsigned long long mult_big_num(unsigned long long a, unsigned long long b, unsigned long long m) {
	unsigned long long sum = 1000000;
	unsigned long long res = 0;
	while (b > sum) {
		res = (res + (a * sum) % m) % m;
		b -= sum;
	}
	res = (res + (a * b) % m) % m;
	return res;
}

unsigned long long bpow(unsigned long long a, unsigned long long n, unsigned long long m) {
	unsigned long long res = 1;
	while (n) {
		if (n & 1) {
			res = mult_big_num(res, a, m);
		}
		a = mult_big_num(a, a, m);
		n >>= 1;
	}

	return res;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	unsigned long long tmp;
	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int is_prime(const unsigned long long p) {
	int n_check = 20;
	for (int i = 0; i < n_check; ++i) {
		unsigned long long rd = rand() % 10000;
		if (gcd(rd, p) == 1) {
			if (bpow(rd, p - 1, p) != 1)
				return 0;
		}
	}
	return 1;
}

int main() {
	unsigned long long n;
	int res;
	srand(time(NULL));
	read_input(&n);

	#if 0
	printf("RAND_MAX: %i\n", RAND_MAX);
	#endif
	res = is_prime(n);

	printf("%d", res);
}
