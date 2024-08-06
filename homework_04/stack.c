#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int x, y;
};


struct stack_node_t {
    struct stack_node_t *next;
    struct node_t *data;
};

void push(struct stack_node_t **stack, struct node_t *data) {
    struct stack_node_t *tmp = calloc(1, sizeof(struct stack_node_t));
    tmp->data = data;
    tmp->next = *stack;
    *stack = tmp;
}

struct node_t *pop(struct stack_node_t **top) {
    struct node_t *data = (*top)->data;
    struct stack_node_t *next = (*top)->next;
    free(*top);
    (*top) = next;
    return data;
}

int main() {

}