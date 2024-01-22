#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_continued_fraction(long long x, long long y) {
	if (y == 0) return;
	printf("%lld ", x / y);
	print_continued_fraction(y, x % y);
}

int main() {
	long long x = 0, y = 0, g;
	long long res;
	
	res = scanf("%lld %lld", &x, &y);
	assert(res == 2);

	print_continued_fraction(x, y);
}
