#include <stdlib.h>
#include <stdio.h>

void read_input(int *a, int *b) {
	int nitems = scanf("%d%d", a, b);
	if (nitems != 2 || b == 0) {
		printf("Incorrect input\n");
		abort();
	}
}

void print_continued_fraction(int a, int b) {
	if (b == 0) {
		return;
	}
	printf("%d ", a / b);
	print_continued_fraction(b, a % b);
}

int main() {
	int a, b;
	read_input(&a, &b);

	print_continued_fraction(a, b);
}
