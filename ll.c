
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

Node ** ll_find_node_link(Node ** head_ptr, Node * to_find) {
  Node ** current_node = head_ptr;
  while (*current_node != NULL) {
    if ((*current_node) == to_find){
      return current_node;
    }
    current_node = &((*current_node)->next);
  }
  return NULL;
}

void ll_delete_node(Node ** head_ptr, Node * to_delete) {
  Node ** current_node = ll_find_node_link(head_ptr, to_delete);
  if (current_node != NULL) {
    Node * next = (*current_node)->next;
    free(*current_node);
    *current_node = next;
  }
}

void ll_insert_node(Node ** head_ptr, Node * to_insert) {
  to_insert->next = *head_ptr;
  *head_ptr = to_insert;
}

void ll_insert_data(Node ** head_ptr, int new_data) {
  Node * new = malloc(sizeof(Node));
  new->data = new_data;
  ll_insert_node(head_ptr, new);
}

void ll_print_nodes(Node * head) {
  Node * current_node = head;
  while (current_node != NULL) {
    printf("%d\n", current_node->data);
    current_node = current_node->next;
  }
}

void main() {
  Node * head = NULL;
  ll_insert_data(&head, 1337);
  ll_insert_data(&head, 1500);
  ll_insert_data(&head, 1111);

  ll_print_nodes(head);
  ll_delete_node(&head, head->next);
  ll_print_nodes(head);
}
