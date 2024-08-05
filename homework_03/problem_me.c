#include <stdio.h>
#include <assert.h> 

int majority_element(const int *parr, int len) {
    int cur_elem = parr[0];
    int vote = 0;
    for (int i = 1; i < len; ++i) {
        assert(vote >= 0);
        if (cur_elem != parr[i]) {
            if (vote == 0) {
                cur_elem = parr[i];
            }
            else {
                --vote;
            }
        }
        else {
            ++vote;
        }
    }
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (parr[i] == cur_elem) ++cnt;
    }
    if (cnt > len / 2) return cur_elem;
    return -1;
}

// Correct res = -1;
void test_1() {
    int n = 7;
    int arr[7] = {1, 1, 8, 9, 7, 8, 4};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = 1;
void test_2() {
    int n = 7;
    int arr[7] = {1, 1, 8, 9, 1, 1, 4};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = -1;
void test_3() {
    int n = 8;
    int arr[8] = {9, 1, 8, 9, 1, 9, 4, 9};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = 9;
void test_4() {
    int n = 9;
    int arr[9] = {9, 1, 8, 9, 9, 1, 9, 4, 9};
    majority_element(arr, n);
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = 2;
void test_5() {
    int n = 5;
    int arr[5] = {2, 3, 1, 2, 2};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = -1;
void test_6() {
    int n = 6;
    int arr[6] = {9, 1, 1, 9, 2, 2};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = 2;
void test_7() {
    int n = 11;
    int arr[11] = {3, 2, 2, 3, 3, 5, 2, 2, 2, 6, 2};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = 4;
void test_8() {
    int n = 9;
    int arr[9] = {3, 4, 3, 2, 4, 4, 2, 4, 4};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

// Correct res = -1;
void test_9() {
    int n = 8;
    int arr[8] = {3, 3, 4, 2, 4, 4, 2, 4};
    int res = majority_element(arr, n);
    printf("res = %d\n", res);
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
}