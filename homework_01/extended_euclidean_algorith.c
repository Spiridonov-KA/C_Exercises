#include <stdio.h>

int extended_gcd(int a, int b, int *x, int *y) {
	int x1, y1, g;
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	g = extended_gcd(b, a % b, &x1, &y1);	
	*x = y1;
	*y = x1 - y1 * a / b;
	return g;
}

int main() {
	int a, b, g, x, y;
	printf("input a and b:\n");
	scanf("%d%d", &a, &b);
	g = extended_gcd(a, b, &x, &y);
	printf("a(%d) + b(%d) = %d = gcd(a, b)\n", x, y, g);
}
