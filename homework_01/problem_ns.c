#include <stdio.h>
#include <stdlib.h>

unsigned int result[100];

void read_input(unsigned int *x, unsigned int *y) {
	int res;
	res = scanf("%d%d", x, y);
	if (res != 2 || *y < 2) {
		printf("Incorrect input!\n");
		abort();
	}
}

void translate(unsigned int x, unsigned int y, unsigned int *size) {
	int i;
	for (i = 0; x; ++i) {
		result[i] = x % y;
		x /= y;
	}
	*size = i;

	for (int j = 0; j < i / 2; ++j) {
		int tmp = result[j];
		result[j] = result[i - 1 - j];
		result[i - 1 - j] = tmp;
	}
}

int main() {
	unsigned int x, y, size;

	read_input(&x, &y);

	translate(x, y, &size);

	for (int i = 0; i < size; ++i) {
		printf("%d", result[i]);
	}
}
