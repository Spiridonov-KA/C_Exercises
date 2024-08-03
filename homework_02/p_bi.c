#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct arr_t {
	char *arr;
	int size;
};

void read_input(struct arr_t *arr, int *num_of_bit) {
	int n, res;
	res = scanf("%d", &n);
	if (res != 1) {
		printf("Incorrect input!\n");
	}

	arr->arr = calloc(n, sizeof(char));
	arr->size = n;

	for (int i = 0; i < n; ++i) {
		res = scanf("%hhu", &(arr->arr[i]));
		if (res != 1) {
			printf("Incorrect input!\n");
		}
	}

	res = scanf("%d", num_of_bit);

	if (res != 1) {
		printf("Incorrect input!\n");
	}
}

void reverse_n_bit(struct arr_t *arr, int n) {
	if (n / 8 >= arr->size) {
		return;
	}

	arr->arr[n / 8] ^= (1 << n % 8);
}

void free_arr(struct arr_t *arr) {
	free(arr->arr);
	free(arr);
	arr->arr = 0;
	arr->size = 0;
}

int main() {
	int num_of_bit;
	struct arr_t *arr;
	arr = calloc(1, sizeof(struct arr_t));
	read_input(arr, &num_of_bit);

	reverse_n_bit(arr, num_of_bit);

	for (int i = 0; i < arr->size; ++i) {
		printf("%hhu ", arr->arr[i]);
	}

	free_arr(arr);
}
