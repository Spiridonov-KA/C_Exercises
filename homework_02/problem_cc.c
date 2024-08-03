#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int const N = 2e6;

struct sieve_t {
	char *sieve;
	unsigned size;
};

void read_input(int *n) {
	int res;
	res = scanf("%d", n);
	if (res != 1) {
		printf("Incorrect input\n");
		abort();
	}
}



unsigned long long sieve_bound(int n) {
	double dnum = n, dres;
	if (n < 20) {
		return 100;
	}
	dres = dnum * (log(dnum) + log(log(dnum)));
	return (unsigned long long) round(dres);
}

void fill_sieve(struct sieve_t *s) {
	for (unsigned i = 2; i * i < s->size; ++i) {
		if (s->sieve[i] == 0) {
			for (unsigned j = i; i * j < s->size; ++j) {
				s->sieve[i * j] = 1;
			}
		}
	}
}

struct sieve_t *init_sieve(const int n) {
	struct sieve_t *s;
	unsigned sieve_len;
	sieve_len = sieve_bound(n);
	s = calloc(1, sizeof(struct sieve_t));
	s->sieve = calloc(sieve_len, sizeof(char));
	s->size = sieve_len;

	fill_sieve(s);
	return s;
}

int count_digits(unsigned n) {
	int res = 0;
	while (n) {
		n /= 10;
		++res;
	}
	return res;
}

unsigned bpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
		}
		a = a * a;
		n >>= 1;
	}
	return res;
}

int is_circular_prime(struct sieve_t *s, unsigned n) {
	unsigned circ = n;
	unsigned n_digits, main_n;
	n_digits = count_digits(n);
	main_n = bpow(10, n_digits - 1);
	for (; n; n /= 10) {
		if (s->sieve[circ])
			return 0;

		circ = main_n * (circ % 10) + circ / 10; 
	}
	return 1;
}

unsigned long long nearest_circular_prime(int n) {
	struct sieve_t *s;
	s = init_sieve(N);

	for (int i = 0;;++i) {
		if (n - i > 1 && is_circular_prime(s, n - i)) {
			return n - i;
		}
		if (is_circular_prime(s, n + i)) {
			return n + i;
		}
	}

	return -1;
}

int main() {
	int n;
	unsigned long long res;
	read_input(&n);

	res = nearest_circular_prime(n);
	assert(res != (unsigned long long)-1);
	printf("%llu", res);
}
