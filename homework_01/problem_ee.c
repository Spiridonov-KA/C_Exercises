#include <stdio.h>
#include <stdlib.h>

long long llabs(long long x) {
	return (x > 0) ? x : -x;
}

void read_input(long long *x, long long *y) {
	long long nitems;
	nitems = scanf("%lld%lld", x, y);
	if (nitems != 2) {
		printf("Incorrect input");
		abort();
	}
}

long long extended_gcd(long long a, long long b, long long *x, long long *y) {
	long long x1, y1, g;
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	g = extended_gcd(b, ((a % b) + llabs(b)) % llabs(b), &x1, &y1);
	*x = y1;
	if (a < 0 && b > 0) {
		*y = x1 - y1 * ((a / b) - 1);
	}
	else if (a < 0 && b < 0) {
		*y = x1 - y1 * ((a / b) + 1);
	}
	else {
		*y = x1 - y1 * (a / b);
	}

	return g;
}


int main() {
	long long x, y, a, b, g;

	read_input(&x, &y);
	g = extended_gcd(x, y, &a, &b);
	printf("%lld %lld %lld", a, b, g);
}
