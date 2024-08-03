#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode *cur_node = head;
    struct ListNode *next_node = head->next;
    head->next = NULL;
    struct ListNode *prev_node;
    while (next_node != NULL) {
        prev_node = cur_node;
        cur_node = next_node;
        next_node = cur_node->next;
        cur_node->next = prev_node;
    }
    return cur_node;
}

int main() {
	ListNode *head = malloc(sizeof(ListNode));
	head->val = 10;
}
