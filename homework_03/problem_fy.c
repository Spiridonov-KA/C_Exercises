#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read_input(int *n, int **arr) {
	int res;
	res = scanf("%d", n);
	*arr = calloc(*n, sizeof(int));
	if (res != 1) {
		printf("Incorrect input\n");
		abort();
	}
	for (int i = 0; i < *n; ++i) {
		res = scanf("%d", &(*arr)[i]);
		if (res != 1) {
			printf("Incorrect input\n");
			abort();
		}
	}
}

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void fisher_yates_shuffle(int *arr, const int n) {
	for (int i = n - 1; i > 0; --i) {
		swap(&arr[i], &arr[myrand() % (i + 1)]);
	}
}

int main() {
	int n;
	int *arr;
	read_input(&n, &arr);
	if (n == 0) {
		printf("0");
		return 0;
	}
	fisher_yates_shuffle(arr, n);

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}

	free(arr);
}
