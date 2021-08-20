
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node * next;
} Node;

/*
typedef struct DoubleNode {
  void * data;
  struct DoubleNode * prev;
  struct DoubleNode * next;
} DoubleNode;
*/

void ll_insert_node(Node ** head_ptr, Node * to_insert) {
  to_insert->next = *head_ptr;
  *head_ptr = to_insert;
}

void ll_delete_node(Node ** head_ptr, Node * to_delete) {
  Node ** current_node = head_ptr;
  while (*current_node != NULL) {
    if ((*current_node) == to_delete){
      Node * next = (*current_node)->next;
      free(*current_node);
      *current_node = next;
      break;
    }
    current_node = &((*current_node)->next);
  }
}

void ll_print_nodes(Node * head) {
  Node * current_node = head;
  while (current_node != NULL) {
    printf("%d\n", current_node->data);
    current_node = current_node->next;
  }
}

void main() {
  Node * head = malloc(sizeof(Node));
  head->data = 1337;

  head->next = malloc(sizeof(Node));;
  head->next->data = 1500;

  head->next->next = malloc(sizeof(Node));;
  head->next->next->data = 1111;

  head->next->next->next = NULL;

  ll_delete_node(&head, head->next);
  ll_print_nodes(head);
}
