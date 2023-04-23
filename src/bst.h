#ifndef BST_H
#define BST_H

#include <stdlib.h>

/**
 * Binary Search Tree (BST)
 * 
 * left : left child node
 * right : right child node
 * value : value of node (also called as key or data)
 * 
 * all nodes are dynamically assigned by malloc()
 * direct access of left, right property can cause unintended behavior
*/
struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    int value;
};

/**
 * initialize bst tree
 * 
 * empty_node : node to be the root node - must be empty
*/
void init_bst(struct bst_node *empty_node);

/**
 * traverse in pre-order
 * 
 * root : root node of bst
*/
void traverse_pre_order_recursive(const struct bst_node *const root);

/**
 * traverse in in-order
 * 
 * root : root node of bst
*/
void traverse_in_order_recursive(const struct bst_node *const root);

/**
 * traverse in post-order
 * 
 * root : root node of bst
*/
void traverse_post_order_recursive(const struct bst_node *const root);

/**
 * search value in bst
 * return pointer of founded node
 * if no value exists, return NULL
 * 
 * root : root node of bst
 * value : value to search
*/
const struct bst_node *const bst_search(const struct bst_node *const root, const int value);

/**
 * insert value in bst
 * if the value already exists, do nothing
 * 
 * root : root node of bst
 * value : value to insert
*/
int bst_insert(const struct bst_node *const root, const int value);

/**
 * delete value in bst
 * if the value not exists, do nothing
 * if the root node does not have any child node, release the root node
 * 
 * root : root node of bst
 * value : value to delete
*/
void bst_delete(const struct bst_node *const root, const int value);

#endif