#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long llabs(long long x) {
	return (x < 0) ? -x : x;
}

long long eu_mod(long long x, long long y) {
	long long r;
	assert(y != 0);
	r = x % y;
	if (r < 0)
		r += llabs(y);
	return r;
}

#if 0
long long gcd(long long x, long long y) {
	long long q;
	q = eu_mod(x, y);
	if (q == 0)
	  return y;
	return gcd(y, q);
}
#endif

long long gcd(long long x, long long y) {
	long long r, tmp;
	x = llabs(x);
	y = llabs(y);
	while (y) {
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}

void read_input(long long *x, long long *y) {
	int res;
	res = scanf("%lld %lld", x, y);
	assert(res == 2);
	if (res != 2) {
		printf("Incorrect input!\n");
		abort();
	}
}

int main() {
	long long x = 0, y = 0, g;

	read_input(&x, &y);
	g = gcd(x, y);

	printf("%lld\n", g);
	return 0;
}