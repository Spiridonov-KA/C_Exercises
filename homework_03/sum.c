#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int sum(int n, ...) {
    int sum = 0;
    va_list args;
    va_start(args, n);
    
    for (int i = 0; i < n; ++i) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

int main() {
    int x1 = sum(2, 1, 3);
    int x2 = sum(3, 1, 3, 5);
    int x3 = sum(4, 1, 3, 5, 7);

    printf("%d %d %d\n", x1, x2, x3);
}