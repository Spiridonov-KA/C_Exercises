#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void read_input(unsigned *n) {
	int nitems;
	nitems = scanf("%u", n);
	if (nitems != 1) {
		printf("Incorrect input\n");
		abort();
	}
}

unsigned long long sieve_bound(unsigned num) {
	double dnum = num, dres;
	if (num - 1 < 20) {
		return 200;
	}
	dres = dnum * (log(dnum) + log(log(dnum)));
	return (unsigned long long) round(dres);

}

void init_sieve(unsigned char *sieve, unsigned long long size) {
	for (unsigned long long j = 2; j * j < size; ++j) {
		for (unsigned long long i = j *j; i < size; i += j) {
			sieve[i] = 1;
		}
	}
}

unsigned long long get_n_prime_number(unsigned n) {
	unsigned long long i, k = 0;
	unsigned long long size = sieve_bound(n);
	unsigned char *sieve = calloc(size, sizeof(unsigned char));

	init_sieve(sieve, size);

	for (i = 2; k < n; ++i) {
		if (sieve[i] == 0) {
			++k;
		}
	}

	return i-1;
}

int main() {

	unsigned n;
	unsigned long long res;
	read_input(&n);
	
	res = get_n_prime_number(n);

	printf("%lld", res);
}
