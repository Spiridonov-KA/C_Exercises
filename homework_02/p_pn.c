#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

struct sieve_t {
	char *sieve;
	unsigned size;
};

void read_input(unsigned long long *n) {
	int res;
	res = scanf("%lld", n);
	if (res != 1) {
		printf("Incorrect input!\n");
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

struct sieve_t* init_sieve(unsigned long long n) {
	struct sieve_t *s = calloc(1, sizeof(struct sieve_t));
	s->sieve = calloc(n, sizeof(char));
	s->size = n;

	fill_sieve(s);

	return s;
}

unsigned long long get_n_prime(struct sieve_t *s, unsigned long long n) {
	unsigned long long i = 2, j = 0;
	for (; j < n; ++i) {
		s->sieve[i] ? 0 : ++j;
	}
	return i - 1;
}

void free_sieve(struct sieve_t* s) {
	free(s);
	s->sieve = 0;
	s->size = 0;
}

int main() {
	unsigned long long n, sieve_len, res;
	struct sieve_t *s;
	read_input(&n);

	sieve_len = sieve_bound(n);
	s = init_sieve(sieve_len);

	res = get_n_prime(s, n);

	printf("%lld", res);

	free_sieve(s);

}
