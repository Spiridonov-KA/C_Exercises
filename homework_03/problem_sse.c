#include <stdio.h>
#include <stdlib.h>

void read_input(int *n, int **arr, int *pos) {
	int res;
	res = scanf("%d", n);
	if (res != 1) {
		printf("Incorrect input!\n");
		abort();
	}
	*arr = calloc(*n, sizeof(int));
	for (int i = 0; i < *n; ++i) {
		res = scanf("%d", &(*arr)[i]);
		if (res != 1) {
			printf("Incorrect input!\n");
			abort();
		}
	}
	res = scanf("%d", pos);
	if (res != 1) {
		printf("Incorrect input!\n");
		abort();
	}
	--(*pos);
}

void selection_sort(int *arr, const int n, const int pos) {
	int min_elem = arr[pos + 1];
	int idx = pos + 1;
	int tmp;
	for (int i = pos + 2; i < n; ++i) {
		if (arr[i] < min_elem) {
			min_elem = arr[i];
			idx = i;
		}
	}
	tmp = arr[pos + 1];
	arr[pos + 1] = min_elem;
	arr[idx] = tmp;
}

int main() {
	int n;
	int *arr;
	int pos;
	read_input(&n, &arr, &pos);
	selection_sort(arr, n, pos);

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
}
