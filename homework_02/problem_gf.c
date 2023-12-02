#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sieve_t {
	unsigned n;
	char *s;
};

struct params_t {
	int a, b, len;
};

void read_input(int *n) {
	int nitems;
	nitems = scanf("%d", n);
	if (nitems != 1) {
		printf("Incorrect input\n");
		abort();
	}

}

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

void init_sieve(struct sieve_t *sieve) {
	sieve->n = 1000000;
	sieve->s = calloc(sieve->n, sizeof(char));
	fill_sieve(sieve);
}

void get_params(struct sieve_t *sieve, struct params_t *param, int n) {
	int max_len = -1, cur_len, n_seq, num;
	for (int i = -(n - 1); i < n; ++i) {
		for (int j = -(n - 1); j < n; ++j) {
			n_seq = 0;
			cur_len = 0;
			num = n_seq * n_seq + i * n_seq + j;
			while (num > 1 && sieve->s[num] == 0) {
				++cur_len;
				++n_seq;
				num = n_seq * n_seq + i * n_seq + j;
			}

			if (cur_len > max_len) {
				max_len = cur_len;
				param->a = i;
				param->b = j;
				param->len = max_len;
			}

		}
	}
}

int main() {
	int n;
	struct sieve_t sieve;
	struct params_t param;
	read_input(&n);

	init_sieve(&sieve);

	get_params(&sieve, &param, n);

	printf("%d %d %d", param.a, param.b, param.len);

}
