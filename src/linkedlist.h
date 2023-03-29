#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define INITIALIZE_NODE(node, prev, next, value) \
node->prev = prev; \
node->next = next; \
node->value = value;

/**
 * node of linked list.
 * 
 * prev : previous node for that node
 * next : next node on that node
 * value : value of the node, other nodes can have same value
*/
struct node {  
    struct node *prev;
    struct node *next;
    int value;
};

/**
 * visit all nodes in the linked list.
 * 
 * entry : entry of linked list
 * print_or_not : decide whether to print to console or not, 0 is false
*/
void retrieve_all(struct node *entry, char print_or_not);

/**
 * return the value of node present in that index.
 * if index is not valid, NULL pointer is returned.
 * value of node can be modified by the recieved pointer.
 * 
 * entry : entry of linked list
 * index : distance from the entry node
*/
int* const at(struct node *entry, int index);

/**
 * returns the first node that has the same value of parameter.
 * if value cannot be found, NULL pointer is returned.
 * value of node can be modified by the recieved pointer.
 * 
 * entry : entry of linked list
 * value : value that want to be found
*/
int* const find_by_value(struct node *entry, int value);

/**
 * insert new node to that index.
 * return 0, if done without problems.
 * returns -1, if index is not valid.
 * 
 * entry : entry of linked list
 * value : value that want to be inserted
 * index : position that want to be inserted
*/
int insert_by_index(struct node *entry, int value, int index);

/**
 * delete new node to that index.
 * return 0, if done without problems.
 * returns -1, if index is not valid.
 * 
 * entry : entry of linked list
 * index : position that want to be deleted
*/
int delete_by_index(struct node *entry, int index);

/**
 * delete the first node that has the same value of parameter.
 * return 0, if done without problems.
 * returns -1, if index is not valid.
 * 
 * entry : entry of linked list
 * value : value that want to be deleted
*/
int delete_by_value(struct node *entry, int value);

/**
 * add a new node at the end of the node.
 * returns 0 if done without problems.
 * returns -1 if some problems are occured.
 * 
 * entry : entry of linked list
 * value : value to be applied to the new node
*/
int push(struct node *entry, int value);

/**
 * remove the last node.
 * 
 * entry : entry of linked list
*/
void pop(struct node *entry);

#endif