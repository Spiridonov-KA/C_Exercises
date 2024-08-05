#include <stdio.h>
#include <stdlib.h>

int *read_input(int *size) {
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

int *get_count_arr(int *arr, int size, int *size_count_arr) {
    int max_elem;
    int *count_arr;
    max_elem = find_max(arr, size) + 1;
    *size_count_arr = max_elem;
    count_arr = calloc(max_elem, sizeof(int));
    for (int i = 0; i < size; ++i) {
        ++count_arr[arr[i]];
    }
    return count_arr;
}

int main() {
    int size, size_count_arr;
    int *arr, *count_arr;
    arr = read_input(&size);
    count_arr = get_count_arr(arr, size, &size_count_arr);

    for (int i = 0; i < size_count_arr; ++i) {
        printf("%d ", count_arr[i]);
    }

    free(arr);
    free(count_arr);
}