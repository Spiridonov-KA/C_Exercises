#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

// определяет длину петли в односвязном списке
// возвращает длину если есть, 0 если петли нет
int loop_len(struct node_t *top) {
    int len;
    struct node_t *fast;
    if (!top || !top->next || !top->next->next) {
        return 0;
    }

    fast = top->next->next;
    while (top != fast) {
        if (!fast->next || !fast->next->next) {
            return 0;
        }
        top = top->next;
        fast = fast->next->next;
    }
    top = top->next;
    len = 1;
    while (top != fast) {
        top = top->next;
        ++len;
    }
    return len;
}

struct node_t *test_1() {
    struct node_t *top, *cycle;
    top = calloc(1, sizeof(struct node_t));
    top->next = calloc(1, sizeof(struct node_t));
    cycle = top->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next->next->next = cycle;
    return top;
}

struct node_t *test_2() {
    struct node_t *top, *cycle;
    top = calloc(1, sizeof(struct node_t));
    top->data = 5;
    top->next = calloc(1, sizeof(struct node_t));
    top->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next->next = calloc(1, sizeof(struct node_t));
    return top;
}

struct node_t *test_3() {
    struct node_t *top, *cycle;
    top = calloc(1, sizeof(struct node_t));
    return top;
}

struct node_t *test_4() {
    struct node_t *top, *cycle;
    top = calloc(1, sizeof(struct node_t));
    top->next = top;
    return top;
}

struct node_t *test_5() {
    struct node_t *top, *cycle;
    top = calloc(1, sizeof(struct node_t));
    cycle = top->next = calloc(1, sizeof(struct node_t));
    top->next->next = calloc(1, sizeof(struct node_t));
    top->next->next->next = cycle;
    return top;
}

int main(int argc, char **argv) {
    struct node_t *top;
    FILE *f;
    int num_tests, res;
    num_tests = 5;
    top = NULL;
    struct node_t * (*tests[256]) () = {test_1, test_2, test_3, test_4, test_5};
    for (int i = 0; i < num_tests; ++i) {
        top = tests[i]();
        res = loop_len(top);
        printf("%d\n", res);
    }
}