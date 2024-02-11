#include <stdio.h>

void read_input(int *x) {
	int nitems;
	nitems = scanf("%d", x);
	if (nitems != 1) {
		printf("Incorrect input\n");
	}
}

void run_rec(int x, int fac) {
	if (x == 0) {
		return;
	}
	run_rec(x / fac, fac + 1);
	printf("%d.", x % fac);
}

void convert_into_factorial(int x) {
	run_rec(x, 2);
}

int main() {
	int x;
	read_input(&x);
	convert_into_factorial(x);

}
