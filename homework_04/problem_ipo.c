#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

struct stack_node_t {
    struct stack_node_t *next;
    void *data;
};

void push(struct stack_node_t **stack, void *data) {
    struct stack_node_t *tmp;
    tmp = calloc(1, sizeof(struct stack_node_t));
    tmp->data = data;
    tmp->next = *stack;
    *stack = tmp;
}

void *pop(struct stack_node_t **stack) {
    void *data;
    struct stack_node_t *tmp;
    data = (*stack)->data;
    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
    return data;
}

void print_pre(struct tree_t *top) {
    struct tree_t *node, *l_subtree, *r_subtree;
    struct stack_node_t *stack = NULL;
    if (top) {
        push(&stack, top);
    }
    while (stack) {
        l_subtree = ((struct tree_t*)stack->data)->left;
        r_subtree = ((struct tree_t*)stack->data)->right;
        node = pop(&stack);
        printf("%d ", node->data);
        if (r_subtree) {
            push(&stack, r_subtree);
        }
        if (l_subtree) {
            push(&stack, l_subtree);
        }
    }
    printf("\n");
}

struct tree_t *tree_1() {
    struct tree_t *top;
    top = calloc(1, sizeof(struct tree_t));
    top->data = 8;
    top->left = calloc(1, sizeof(struct tree_t));
    top->left->data = 4;
    top->right = calloc(1, sizeof(struct tree_t));
    top->right->data = 10;
    return top;
}

struct tree_t *tree_2() {
    struct tree_t *top;
    top = calloc(1, sizeof(struct tree_t));
    top->data = 8;
    top->left = calloc(1, sizeof(struct tree_t));
    top->left->data = 4;
    top->right = calloc(1, sizeof(struct tree_t));
    top->right->data = 10;
    top->left->left = calloc(1, sizeof(struct tree_t));
    top->left->left->data = 3;
    top->left->right = calloc(1, sizeof(struct tree_t));
    top->left->right->data = 2;
    return top;
}

int main() {
    struct tree_t *top;
    int num_tests, res;
    num_tests = 2;
    top = NULL;
    struct tree_t *(*tests[256]) () = {tree_1, tree_2};
    for (int i = 0; i < num_tests; ++i) {
        top = tests[i]();
        print_pre(top);
    }
}