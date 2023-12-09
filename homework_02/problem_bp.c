#include <stdio.h>
#include <stdlib.h>

void find_pos(int n, int *l, int *r) {
	*l = -1;
	*r = -1;
	for (int k = 0; n > 0; n >>= 1, ++k) {
		if (*r == -1 && n & 1) {
			*r = k;
		}
		if (n == 1) {
			*l = k;
		}
	}
}

int main() {
	int n, l, r;
	scanf("%d", &n);

	if (n) {
		find_pos(n, &l, &r);
		printf("%d %d", l, r);
	}
	else {
		printf("-1");
	}
}
