#ifndef LL
#define LL

typedef struct Node {
  int data;
  struct Node * next;
} Node;

void ll_print_nodes(Node *);
Node * ll_create_node(int);

void ll_delete_node(Node **, Node *);

void ll_insert_node_front(Node **, Node *);
void ll_insert_node_before(Node **, Node *, Node *);
void ll_insert_node_after(Node **, Node *, Node *);
void ll_insert_node_sorted(Node **, Node *);

void ll_insert_data_front(Node **, int);
void ll_insert_data_before(Node **, int, Node *);
void ll_insert_data_after(Node **, int, Node *);
void ll_insert_data_sorted(Node **, int);

#endif