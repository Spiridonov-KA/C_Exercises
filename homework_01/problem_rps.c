#include <stdio.h>
#include <stdlib.h>

#if 1
unsigned bin_pow(unsigned a, unsigned b, unsigned m) {
	unsigned res = 1, mult = a;
	while (b) {
		if (b % 2) {
			res *= mult;
			res %= m;
		}
		mult *= mult;
		mult %= m;
		b /= 2;
	}

	return res;
}
#endif


#if 0
unsigned bin_pow(unsigned a, unsigned b) {
	unsigned res = 1, mult = a;
	while (b) {
		if (b % 2) {
			res *= mult;
		}
		mult *= mult;
		b /= 2;
	}

	return res;
}
#endif

unsigned spow_mod(unsigned n, unsigned k, unsigned m) {
	unsigned res = n % m;
	while (k) {
		// res = bin_pow(n, res);
		res = bin_pow(res, k, m);
		--k;
	}

	return res % m;
}

void read_input(unsigned *a, unsigned *b, unsigned *n) {
	printf("input a, b and n\n");
	scanf("%d%d%d", a, b, n);
}

int main() {
	unsigned a, b, p, n;
	
	read_input(&a, &b, &n);
	// r = bin_pow(a, b, n);
	p = spow_mod(a, b, n);
	printf("%d", p);
	// printf("a^^b = %d\n", p);
}
