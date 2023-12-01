#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void read_input(unsigned long long *n) {
	int nitems = scanf("%lld", n);
	if (nitems != 1) {
		printf("Incorrect input\n");
		abort();
	}
}

unsigned long long sieve_bound(unsigned long long n) {
	double dn, dres;
	if (n < 20) {
		return 100;
	}
	dn = n;
	dres = dn * (log(dn) + log(log(dn)));
	return (unsigned long long) round(dres);
}

void init_sieve(unsigned char *sieve, unsigned long long size) {
	unsigned long long i, j;
	for (i = 2; i * i <= size; ++i) {
		for (j = i * i; j <= size; j += i) {
			// printf("%lld\n", j);
			sieve[j] = 1;
		}
	}
}

unsigned long long get_number_of_prime_numbers(unsigned long long n) {
	unsigned char *sieve;
	unsigned long long res = 0;

	n += 1;
	sieve = calloc(n, sizeof(unsigned char));

	init_sieve(sieve, n);

	for (unsigned long long i = 2; i < n; ++i) {
		if (sieve[i] == 0) {
			++res;
			// printf("%lld\n", i);
		}
	}

	return res;
}

int main() {
	unsigned long long n, res;

	read_input(&n);

	res = get_number_of_prime_numbers(n);

	printf("%lld", res);
}
