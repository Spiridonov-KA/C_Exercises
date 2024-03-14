#include <stdio.h>
#include <stdlib.h>

int moveright(int *arr, int key, int last) {
	for (int i = 0; i < last; ++i) {
		if (arr[i] > key) {
			for (int j = last; j > i; --j) {
				arr[j] = arr[j - 1];
			}
			return i;
		}
	}
	return last;
}

void inssort(int *arr, int len) {
	int i;
	for (i = 0; i < len; ++i) {
		int key, pos;
		key = arr[i];
		pos = moveright(arr, key, i);
		arr[pos] = key;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int *arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	inssort(arr, n);

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	free(arr);
}
