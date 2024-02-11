//-----------------------------------------------------------------------------
//
// This program solve Diophantine equation that takes the form
//                      ax + by = c,
// where a, b and c are given integers.
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

long long llabs(long long x) {
	return (x < 0) ? -x : x;
}

void read_input(long long *a, long long *b, long long *c) {
	int nitems;
	nitems = scanf("%lld%lld%lld", a, b, c);
	if (nitems != 3) {
		printf("Incorrect input");
		abort();
	}
}

#if 0
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
	long long x1, y1, g;
	if (b == 0) {
		*x = llabs(a) / a;
		*y = 0;
		return llabs(a);
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
#endif

long long extended_gcd_main(long long a, long long b, long long *x, long long *y) {
	long long x1, y1, g;
	if (!b) {
		*x = 1;
		*y = 0;
		return a;
	}
	g = extended_gcd_main(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - (a / b) * y1;
	return g;
}

long long extended_gcd(long long a, long long b, long long *x, long long *y) {
	long long g;
	g = extended_gcd_main(llabs(a), llabs(b), x, y);
	*x *= (a / llabs(a));
	*y *= (b / llabs(b));
	return g;
}

int solve_diophantine_eq(long long a, long long b, long long c, long long *x, long long *y) {
	long long g;
	g = extended_gcd(a, b, x, y);
	if (c % g != 0) {
		return 0;
	}
	*x *= (c / g);	
	*y *= (c / g);	
	return 1;
}

int main() {
	long long a, b, x, y, c;
	int res = 0;
	read_input(&a, &b, &c);

	res = solve_diophantine_eq(a, b, c, &x, &y);	
	if (res) {
		printf("%lld %lld", x, y);
	}
	else {
		printf("NONE");
	}
}
