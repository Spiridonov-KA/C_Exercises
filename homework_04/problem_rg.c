#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

typedef int (*generator_t)(int);

unsigned cycle_len(generator_t gen) {
    int l_val = 0, r_val = 0, r_edge = 1;
    for(int i = 0, j = 0; ;) {
        if (j < r_edge) {
            r_val = gen(r_val);
            ++j;
            continue;
        }
        if (i == j) {
            r_edge *= 2;
            continue;
        }
        if (l_val == r_val) {
            return j - i;
        }
        l_val = gen(l_val);
        ++i;
    }
    assert(0);
}

int f1(int x) {
    return x % 1;
}

int f2(int x) {
    return (x + 2) % 5;
}

int f3(int x) {
    return (x + 2) % 5 + 3;
}

int f4(int x) {
    return (3 * x + 2) % 5 + 4;
}


int main() {
    printf("%d\n", cycle_len(f1));
    printf("%d\n", cycle_len(f2));
    printf("%d\n", cycle_len(f3));
    printf("%d\n", cycle_len(f4));
}