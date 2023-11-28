#include <stdio.h>
#include <stdlib.h>

const int N = 50;

long long fib_numbers[50] = {0};

void read_input(long long *x) {
	int nitems;
	nitems = scanf("%lld", x);
	if (nitems != 1) {
		printf("Incorrenct input\n");
		abort();
	}
}

void calculate_number_fib() {
	fib_numbers[1] = 1;
	for (int i = 2; i < N; ++i) {
		fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
	}
}

long long find_nearest_fib_number(long long x) {
	long long res = 1;
	while (x - fib_numbers[res] >= 0) {
		++res;
	}
	return res-1;
}

void convert_into_fib(long long x) {
	long long i = find_nearest_fib_number(x);
	while (i - 1) {
		if (x - fib_numbers[i] >= 0) {
			// printf("%lld\n", fib_numbers[i]);
			x -= fib_numbers[i];
			printf("1");
		}
		else {
			printf("0");
		}
		--i;
	}
}

int main() {
	long long x, res;

	read_input(&x);
	calculate_number_fib();
	
	convert_into_fib(x);
}
