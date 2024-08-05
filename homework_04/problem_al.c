#include <stdio.h>
#include <stdlib.h>

struct node_t {
  struct node_t *next;
  int data;
};

struct node_t *read_list(FILE *inp) {
    int val, res;
    struct node_t *odd_list, *even_list, *top_odd, *top_even; 
    odd_list = NULL;
    even_list = NULL;
    top_even = top_odd = NULL;
    for(;;) {
        res = fscanf(inp, "%d", &val);
        if (res == EOF) {
            break;
        }
        if (res != 1) {
            fprintf(stderr, "File have broken format");
            abort();
        }
        if (val % 2 == 1) {
            if (odd_list) {
                odd_list->next = calloc(1, sizeof(struct node_t));
                odd_list = odd_list->next;
            }
            else {
                top_odd = calloc(1, sizeof(struct node_t));
                odd_list = top_odd;
            }
            odd_list->data = val;
        }
        else {
            if (even_list) {
                even_list->next = calloc(1, sizeof(struct node_t));
                even_list = even_list->next;
            }
            else {
                top_even = calloc(1, sizeof(struct node_t));
                even_list = top_even;
            }
            even_list->data = val;
        }
    }
    if (!top_even && !top_odd) {
        return NULL;
    }
    if (top_even && !top_odd) {
        return top_even;
    }
    if (top_odd && !top_even) {
        return top_odd;
    }
    even_list->next = top_odd;
    return top_even;
}

void delete_list(struct node_t *top) {
    struct node_t *prev;
    while (top) {
        prev = top;
        top = top->next;
        free(prev);
    }
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
        delete_list(top);
        top = NULL;
    }
}