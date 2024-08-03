#include <stdio.h>
#include <stdlib.h>

void read_input(int *n, int **arr) {
	int res;
	res = scanf("%d", n);
	if (res != 1) {
		printf("Incorrect input\n");
		abort();
	}
	*arr = calloc(*n, sizeof(int));
	for (int i = 0; i < *n; ++i) {
		// scanf("%d", (*arr) + i);
		res = scanf("%d", &(*arr)[i]);
		if (res != 1) {
			printf("Incorrect input\n");
			abort();
		}
	}
}

int find_min(const int *arr, const int n) {
	int res = arr[0];
	if (n == 0)
		return 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i] < res) {
			res = arr[i];
		}
	}

	return res;
}

int find_max(const int *arr, const int n) {
	int res = arr[0];
	if (n == 0)
		return 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i] > res) {
			res = arr[i];
		}
	}

	return res;
}

int main() {
	int n;
	int *arr;
	int min_res, max_res;
	read_input(&n, &arr);

	min_res = find_min(arr, n);
	max_res = find_max(arr, n);
	printf("%d %d", min_res, max_res);

	free(arr);
}
