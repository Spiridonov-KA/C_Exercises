#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long pisanos[1000000] = { 0, 1, 3, 8, 6, 24, 16 };

void read_input(unsigned long long *x, unsigned long long *m) {
	int nitems;
	nitems = scanf("%llu%llu", x, m);
	if (nitems != 2) {
		printf("Incorrect input\n");
		abort();
	}
}

unsigned long long get_pisano_period(unsigned long long m) {
	unsigned long long first = 0ull, second = 1ull;
	for (int idx = 2; ; ++idx) {
		unsigned long long tmp = second;
		second = (first + second) % m;
		first = tmp;
		if (first == 0 && second == 1) {
			return idx - 1;
		}
	}
}

unsigned long long fib_mod(unsigned long long n, unsigned long long m) {
	unsigned long long first = 0ull, second = 1ull, tmp;
	assert(m > 0);
	if (m < 1000000) {
		if (pisanos[m] == 0) {
			pisanos[m] = get_pisano_period(m);
		}
		n = n % pisanos[m];
	} 
	else {
		n = n % get_pisano_period(m);
	}
	if (n == 0) {
		return 0;
	}
	for (int idx = 2; idx < n + 1 ; ++idx) {
		tmp = second;
		second = (first + second) % m;
		first = tmp;
	}

	return second;
}

int main() {
	unsigned long long x, m, res;

	read_input(&x, &m);
	
	res = fib_mod(x, m);	
	if (m < 1000000)
		printf("%llu %llu", res, pisanos[m]);
	else {
		printf("%llu %llu", res, get_pisano_period(m));
	}
}
