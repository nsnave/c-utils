#ifndef LL
#define LL

typedef struct NodeLL {
  int data;
  struct NodeLL * next;
} NodeLL;

void ll_print_nodes(NodeLL *);
NodeLL * ll_create_node(int);

void ll_delete_node(NodeLL **, NodeLL *);

void ll_insert_node_front(NodeLL **, NodeLL *);
void ll_insert_node_before(NodeLL **, NodeLL *, NodeLL *);
void ll_insert_node_after(NodeLL **, NodeLL *, NodeLL *);
void ll_insert_node_sorted(NodeLL **, NodeLL *);

void ll_insert_data_front(NodeLL **, int);
void ll_insert_data_before(NodeLL **, int, NodeLL *);
void ll_insert_data_after(NodeLL **, int, NodeLL *);
void ll_insert_data_sorted(NodeLL **, int);

#endif