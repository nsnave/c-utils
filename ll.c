
#include <stdlib.h>
#include <stdio.h>

#include "ll.h"

/*** Utility Functions ***/

void ll_print_nodes(NodeLL * head) {
  NodeLL * current_node = head;
  while (current_node != NULL) {
    printf("%d\n", current_node->data);
    current_node = current_node->next;
  }
}

NodeLL * ll_create_node(int new_data) {
  NodeLL * new = malloc(sizeof(NodeLL));
  new->data = new_data;
  return new;
}

NodeLL ** ll_find_node_ptr(NodeLL ** head_ptr, NodeLL * to_find) {
  // Finds the location of the node to_find in the list
  NodeLL ** current_node = head_ptr;
  while (*current_node != NULL) {
    if ((*current_node) == to_find) break;
    current_node = &((*current_node)->next);
  }
  return current_node;
}


/*** Delete Node Function ***/

void ll_delete_node(NodeLL ** head_ptr, NodeLL * to_delete) {
  NodeLL ** current_node = ll_find_node_ptr(head_ptr, to_delete); // *current_node == to_delete
  if (*current_node != NULL) {
    NodeLL * next = (*current_node)->next;
    free(*current_node);
    *current_node = next;
  }
}


/*** Insertion Node Functions ***/

void ll_insert_node_front(NodeLL ** head_ptr, NodeLL * to_insert) {
  to_insert->next = *head_ptr;
  *head_ptr = to_insert;
}

void ll_insert_node_before(NodeLL ** head_ptr, NodeLL * to_insert, NodeLL * key_node) {
  NodeLL ** current_node = ll_find_node_ptr(head_ptr, key_node);  // *current_node == key_node
  to_insert->next = *current_node;
  *current_node = to_insert;
}

void ll_insert_node_after(NodeLL ** head_ptr, NodeLL * to_insert, NodeLL * key_node) {
  NodeLL ** current_node = ll_find_node_ptr(head_ptr, key_node);  // *current_node == key_node
  to_insert->next = (*current_node)->next;
  (*current_node)->next = to_insert;
}

void ll_insert_node_sorted(NodeLL ** head_ptr, NodeLL * to_insert) {
  // Finds the location to insert the node
  NodeLL ** current_node = head_ptr;
  while (*current_node != NULL) {
    if (to_insert->data <= (*current_node)->data) break;
    current_node = &((*current_node)->next);
  }

  // Inserts the node
  to_insert->next = *current_node;
  *current_node = to_insert;
}


/*** Insertion Data Functions ***/

void ll_insert_data_front(NodeLL ** head_ptr, int new_data) {
  NodeLL * new = ll_create_node(new_data);
  ll_insert_node_front(head_ptr, new);
}

void ll_insert_data_before(NodeLL ** head_ptr, int new_data, NodeLL * key_node) {
  NodeLL * new = ll_create_node(new_data);
  ll_insert_node_before(head_ptr, new, key_node);
}

void ll_insert_data_after(NodeLL ** head_ptr, int new_data, NodeLL * key_node) {
  NodeLL * new = ll_create_node(new_data);
  ll_insert_node_after(head_ptr, new, key_node);
}

void ll_insert_data_sorted(NodeLL ** head_ptr, int new_data) {
  NodeLL * new = ll_create_node(new_data);
  ll_insert_node_sorted(head_ptr, new);
}


/*** Main ***/

void main() {
  NodeLL * head = NULL;
  ll_insert_data_sorted(&head, 1337);
  ll_insert_data_sorted(&head, 1500);
  ll_insert_data_sorted(&head, 1111);

  ll_print_nodes(head);
  ll_delete_node(&head, head->next);
  ll_insert_data_sorted(&head, 1600);
  ll_insert_data_sorted(&head, 1900);
  ll_insert_data_sorted(&head, 1800);

  printf("\n");
  ll_print_nodes(head);
}
