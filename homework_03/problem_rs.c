#include <stdio.h>
#include <stdlib.h>

int *read_input(int *size, int *radix_num) {
    int res;
    int *arr;
    res = scanf("%d", size);
    if (res < 1) {
        printf("Incorrect input\n");
        abort();
    }
    arr = malloc(sizeof(int) * (*size));
    for (int i = 0; i < *size; ++i) {
        scanf("%d", arr + i);
    }
    res = scanf("%d", radix_num);
    if (res < 1) {
        printf("Incorrect input\n");
        abort();
    }
    return arr;
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

void zero_arr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void radix_sort(int **original_arr, int size) {
    int max_elem, cur_radix;
    int *counts, *pos, *arr;
    int *prev_arr, *tmp;
    cur_radix = 1;
    counts = calloc(10, sizeof(int));
    pos = calloc(10, sizeof(int));
    arr = *original_arr;
    prev_arr = calloc(size, sizeof(int));
    max_elem = find_max(arr, size);
    for (;max_elem; max_elem /= 10) {
        for (int i = 0; i < size; ++i) {
            ++counts[(arr[i] / cur_radix) % 10];
        }
        for (int i = 1; i < 10; ++i) {
            pos[i] = pos[i-1] + counts[i-1];
        }
        for (int i = 0; i < size; ++i) {
            prev_arr[pos[(arr[i] / cur_radix) % 10]++] = arr[i];
        }
        cur_radix *= 10;
        tmp = arr;
        arr = prev_arr;
        prev_arr = tmp;
        zero_arr(counts, 10);
        zero_arr(pos, 10);
    }
    free(counts);
    free(pos);
    free(prev_arr);
    *original_arr = arr;
}

void sort_specific_radix(int **original_arr, int size, int radix_num) {
    int max_elem, cur_radix;
    int *counts, *pos, *arr;
    int *prev_arr, *tmp;
    cur_radix = 1;
    for (int i = 0; i < radix_num; ++i) {
        cur_radix *= 10;
    }
    counts = calloc(10, sizeof(int));
    pos = calloc(10, sizeof(int));
    arr = *original_arr;
    prev_arr = calloc(size, sizeof(int));
    max_elem = find_max(arr, size);
    for (int i = 0; i < size; ++i) {
        ++counts[(arr[i] / cur_radix) % 10];
    }
    for (int i = 1; i < 10; ++i) {
        pos[i] = pos[i-1] + counts[i-1];
    }
    for (int i = 0; i < size; ++i) {
        prev_arr[pos[(arr[i] / cur_radix) % 10]++] = arr[i];
    }
    cur_radix *= 10;
    tmp = arr;
    arr = prev_arr;
    prev_arr = tmp;
    free(counts);
    free(pos);
    free(prev_arr);
    *original_arr = arr;
}

int main() {
    int size, radix_num;
    int *arr;
    arr = read_input(&size, &radix_num);
    sort_specific_radix(&arr, size, radix_num);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
}