#include <stdio.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int int_comp(const void *lhs, const void *rhs) {
    const int *int_lhs = (const int *) lhs;
    const int *int_rhs = (const int *) rhs;
    return *int_lhs - *int_rhs;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {
    int l = -1, r = num, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (cmp(base + m * size, key) > 0) {
            r = m - 1;
        }
        else if (cmp(base + m * size, key) < 0) {
            l = m + 1;
        }
        else {
            return (base + m * size);
        }
    }
    return NULL;
}

int main() {
    int arr_1[6] = {1, 1, 2, 3, 10, 12};
    int key = 10;
    int *res_int = cbsearch(&key, arr_1, 6, sizeof(int), int_comp);
    if (res_int != NULL) 
        printf("res_int = %d\n", *res_int);
    else
        printf("Element wasn't found\n");
}