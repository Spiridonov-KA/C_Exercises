#include <stdio.h>
#include <stdlib.h>

struct node_t {
  struct node_t *next;
  int data;
};

struct node_t * reverse(struct node_t *top) {
    struct node_t *prev = NULL, *next, *cur = top;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct node_t *read_list(FILE *inp) {
    int val, res;
    struct node_t *lst = NULL, *top = NULL;
    for(;;) {
        res = fscanf(inp, "%d", &val);
        if (res == EOF) {
            break;
        }
        if (res != 1) {
            fprintf(stderr, "File have broken format");
            abort();
        }
        if (!lst) {
            lst = calloc(1, sizeof(struct node_t));
            top = lst;
        }
        else {
            lst->next = calloc(1, sizeof(struct node_t));
            lst = lst->next;
        }
        lst->data = val;
    }
    return top;
}

void print_list(struct node_t *node) {
    while (node && node->next) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    if (node) {
        printf("%d", node->data);
    }
    printf("\n");
}

int main() {
    struct node_t *top;
    FILE *f;
    int num_tests;
    num_tests = 4;
    top = NULL;
    char tests[256][256] = {"001.dat", "002.dat", "003.dat", "004.dat"};
    for (int i = 0; i < num_tests; ++i) {
        f = fopen(tests[i], "r");
        if (!f) {
            perror("File error");
            abort();
        }
        top = read_list(f);
        print_list(top);
        top = reverse(top);
        print_list(top);
        top = NULL;
    }
}