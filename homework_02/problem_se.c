#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct sieve_t {
	char *sieve;
	unsigned size;
};

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

void fill_sieve(struct sieve_t *s) {
	for (unsigned i = 2; i * i < s->size + 10; ++i) {
		if (s->sieve[i] == 0) {
			for (unsigned j = i; i * j < s->size + 10; ++j) {
				s->sieve[i * j] = 1;
			}
		}
	}
}

struct sieve_t* init_sieve(unsigned long long n) {
	struct sieve_t *s = calloc(1, sizeof(struct sieve_t));
	s->sieve = calloc(n, sizeof(char));
	s->size = n;

	fill_sieve(s);

	return s;
}

unsigned long long count_primes_no_greater(struct sieve_t *s, unsigned long long n) {
	unsigned long long res = 0;
	for (unsigned long long i = 2; i <= n; ++i) {
		if (s->sieve[i] == 0) {
			++res;
		}
	}
	return res;
}

unsigned long long get_number_of_prime_numbers(unsigned long long n) {

	unsigned long long sieve_len, prime_numbers;
	struct sieve_t *s;

	sieve_len = sieve_bound(n);
	s = init_sieve(sieve_len);


	prime_numbers = count_primes_no_greater(s, n);
	return prime_numbers;
}

int main() {
	unsigned long long n, res;

	read_input(&n);

	res = get_number_of_prime_numbers(n);

	printf("%lld", res);
}
