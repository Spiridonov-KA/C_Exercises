#include <stdio.h>

int sum(int x, int y) {
    return x + y;
}

int main() {
    int (*p_sum)(int, int);
    p_sum = sum;
    int res_sum = (*p_sum)(8, 9);
    printf("Res pointer to sum res = %d\n", res_sum);
}