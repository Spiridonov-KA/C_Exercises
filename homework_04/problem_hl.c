#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

// определяет есть ли петля в односвязном списке
// возвращает 0 если нет и 1 если есть
int list_is_a_loop(struct node_t *top) {
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
    return 1;
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

int main(int argc, char **argv) {
    struct node_t *top;
    FILE *f;
    int num_tests, res;
    num_tests = 4;
    top = NULL;
    struct node_t * (*tests[256]) () = {test_1, test_2, test_3, test_4};
    for (int i = 0; i < num_tests; ++i) {
        top = tests[i]();
        res = list_is_a_loop(top);
        printf("%d\n", res);
    }
}