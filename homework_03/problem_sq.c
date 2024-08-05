#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#if 0
unsigned partition(int *arr, unsigned low, unsigned high) {
    unsigned l = low + 1;
    unsigned r = high;
    for (; l <= r;) {
        if (arr[l] > arr[low]) {
            if (arr[r] <= arr[low]) {
                swap(arr + l, arr + r);
                ++l;
            }
            --r;
        }
        else if (arr[r] <= arr[low]) {
            if (arr[l] > arr[low]) {
                swap(arr + l, arr + r);
                --r;
            }
            ++l;
        }
        else {
            ++l; --r;
        }
    }
    if (l == r && l == low + 1) {
        return low;
    }
    if (l == r && r == high) {
        swap(arr, arr + high);
        return high;
    }
    swap(arr, arr + l - 1);
    return l - 1;
}
#endif

unsigned partition(int *arr, unsigned low, unsigned high) {
    int key = arr[low];
    unsigned l = low + 1;
    unsigned r = high;
    while (l <= r) {
        if (arr[l] < key) {
            ++l; continue;
        }
        if (arr[r] > key) {
            --r; continue;
        }
        assert(arr[l] >= arr[r]);
        swap(arr + l, arr + r);
        ++l; --r;
    }
    if (l == r && l == low + 1) {
        return low;
    }
    if (l == r && r == high) {
        swap(arr, arr + high);
        return high;
    }
    swap(arr, arr + l - 1);
    return l - 1;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
    if (low >= high) return;
    unsigned pi = partition(arr, low, high);
    if (pi > low) qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void qsort(int *arr, unsigned len) {
    qsort_impl(arr, 0u, len - 1);
}

void check_arr(int *a, int *b, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            printf("Values don't match i = %d;\n", i);
        }
    }
}

void test_1() {
    int size = 8;
    int arr[8] = {6, 8, 3, 2, 1, 9, 7, 2};
    partition(arr, 0, size - 1);
    int correct_ans[8] = {1, 2, 3, 2, 6, 9, 7, 8};
    check_arr(arr, correct_ans, size);
}

void test_2() {
    int size = 5;
    int arr[5] = {3, 3, 3, 5, 6};
    partition(arr, 0, size - 1);
    int correct_ans[8] = {3, 3, 3, 5, 6};
    check_arr(arr, correct_ans, size);
}

void test_3() {
    int size = 5;
    int arr[5] = {1, 3, 3, 3, 3};
    int ans = partition(arr, 0, size - 1);
    int correct_ans[8] = {1, 3, 3, 3, 3};
    check_arr(arr, correct_ans, size);
    printf("pos = %d\n", ans);
}

void test_4() {
    int size = 5;
    int arr[5] = {5, 3, 3, 3, 3};
    int ans = partition(arr, 0, size - 1);
    int correct_ans[8] = {3, 3, 3, 3, 5};
    check_arr(arr, correct_ans, size);
    printf("pos = %d\n", ans);
}

void test_5() {
    int size = 8;
    int arr[8] = {6, 8, 3, 2, 10, 9, 7, 2};
    partition(arr, 0, size - 1);
    int correct_ans[8] = {2, 2, 3, 6, 10, 9, 7, 8};
    check_arr(arr, correct_ans, size);
}


int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}