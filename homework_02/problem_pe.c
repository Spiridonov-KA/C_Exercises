#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct sieve_t {
  unsigned char *s;
  int n;
};

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

void fill_sieve(struct sieve_t *sv) {
	for (int i = 2; i * i < 8 * sv->n; ++i) {
		if ((((sv->s[i / 8]) >> (i % 8)) & 1) == 0) {
			for (int j = i; i * j < 8 * sv->n; ++j) {
				sv->s[i * j / 8] |= (1 << ((i * j) % 8));
			}
		}
	}
}

int is_prime(struct sieve_t *sv, unsigned n) {
	return (((sv->s[n / 8]) >> (n % 8)) & 1) ? 0 : 1;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

void print_byte(unsigned char n) {
	int m = n;
	m = (1 << 8) + n;
	while (m > 1) {
		if (m & 1) {
			printf("1");
		}
		else {
			printf("0");
		}
		m >>= 1;
	}
	printf("\n");
}

int main() {
	int n = 100;
	struct sieve_t *sv = calloc(1, sizeof(struct sieve_t));
	sv->s = calloc(n, sizeof(unsigned char));
	sv->n = n;
	fill_sieve(sv);
	#if 0
	for (int i = 0; i < min(8 * n, 100); ++i) {
		print_byte(sv->s[i]);
	}
	printf("\n");
	for (int i = 0 ; i < min(8 * n, 100); ++i) {
		printf("%d is prime: %d\n", i, is_prime(sv, i));
	}
	#endif
}
