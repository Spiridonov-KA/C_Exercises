#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 0
struct sieve_t {
  int n;
  char *s;
};
#endif

void fill_sieve(struct sieve_t *sv) {
	unsigned int i, j;
	for (i = 2; i * i <= sv->n; ++i) {
		if (sv->s[i] == 0) {
			for (j = i * i; j <= sv->n; j += i) {
				sv->s[j] = 1;
			}
		}
	}
}

int nth_prime(struct sieve_t *sv, int N) {
	int i, k = 0;
	for (i = 2; k < N; ++i) {
		if (sv->s[i] == 0) 
			++k;
	}

	return i-1;
}

#if 0
int main() {
	int n, res, size = 1000000000;
	struct sieve_t sieve;
	scanf("%d", &n);
	sieve.s = calloc(size, sizeof(char));
	sieve.n = size;
	fill_sieve(&sieve);
	printf("HERE\n");
	res = nth_prime(&sieve, n);
	printf("%d", res);

	free(sieve.s);
}
#endif
