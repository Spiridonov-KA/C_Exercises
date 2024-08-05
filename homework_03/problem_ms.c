#include <stdio.h>

void merge(int *arr, int l, int m, int r);

void merge_sort_imp(int *arr, int l, int r) {
  if (l >= r) return;
  int m = (l + r) / 2;
  merge_sort_imp(arr, l, m);
  merge_sort_imp(arr, m + 1, r);
  merge(arr, l, m, r);
}

void merge_sort(int *arr, int n) {
  merge_sort_imp(arr, 0, n - 1);
}

void merge(int *arr, int l, int m, int r) {
    int tmp[r - l + 1];
    int l_ptr = l, r_ptr = m + 1;
    for (int i = 0; i < r - l + 1; ++i) {
        if (l_ptr <= m && arr[l_ptr] <= arr[r_ptr] || r_ptr == r + 1) {
            tmp[i] = arr[l_ptr];
            ++l_ptr;
            continue;
        }
        if (r_ptr <= r && arr[r_ptr] <= arr[l_ptr] || l_ptr == m + 1) {
            tmp[i] = arr[r_ptr];
            ++r_ptr;
            continue;
        }
    }
    for (int i = l; i <= r; ++i) {
        arr[i] = tmp[i - l];
    }
}

void test_1() {
    int arr[12] = {1, 1, 3, 5, 9, 12, 2, 8, 9, 10, 14, 18};
    merge(arr, 0, 5, 11);
    for (int i = 0; i < 12; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test_2() {
    int arr[6] = {2, 2, 2, 1, 1, 1};
    merge(arr, 0, 2, 5);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    test_1();
    test_2();
}