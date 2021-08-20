
#include <stdlib.h>
#include <stdio.h>

typedef struct NodeBST {
  int data;
  struct NodeBST * left;
  struct NodeBST * right;
} NodeBST;


/*** Utility Functions ***/

NodeBST * bst_create_node(int new_data) {
  NodeBST * new = malloc(sizeof(NodeBST));
  new->data = new_data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

/**
  * Returns a pointer to the node containing data equal to `to_find`.
  */
NodeBST ** bst_find_data(NodeBST ** root, int to_find) {
  NodeBST ** current_node = root;
  while (*current_node != NULL) {
    int curr_data = (*current_node)->data;

    if (to_find < curr_data) {
      current_node = &((*current_node)->left);
    }
    else if (to_find > curr_data) {
      current_node = &((*current_node)->right);
    }
    else {  // to_find == curr_data
      break;
    }

  }
  return current_node;
}


/*** Insert Functions ***/

void bst_insert_data(NodeBST ** root, int to_insert) {
  NodeBST ** insert_location = bst_find_data(root, to_insert);
  if (*insert_location == NULL) {
    NodeBST * new_node = bst_create_node(to_insert);
    *insert_location = new_node;
  }
}


/*** Main ***/

void main() {
  NodeBST * root = NULL;
  bst_insert_data(&root, 3);
  bst_insert_data(&root, 2);
  bst_insert_data(&root, 5);
  bst_insert_data(&root, 4);
}