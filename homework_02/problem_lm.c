#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

unsigned long long ullabs(unsigned long long a) {
	return a > 0 ? a : -a;
}


void read_input(int *n) {
	int res;
	res = scanf("%d", n);
	if (res != 1) {
		printf("Incorrect input\n");
		abort();
	}
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	unsigned long long tmp;
	a = ullabs(a);
	b = ullabs(b);

	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	
	return a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return a * b / gcd(a, b);
}


unsigned long long find_lcm_from_to(int a, int b) {
	unsigned long long res = a;
	assert(a <= b);

	for (int i = a + 1; i <= b; ++i) {
		res = lcm(res, (unsigned long long)i);
	}

	return res;
}

int main() {
	int n;
	unsigned long long res;

	read_input(&n);

	res = find_lcm_from_to(2, n);

	printf("%llu", res);
}
