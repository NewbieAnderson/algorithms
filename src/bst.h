#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Binary Search Tree (BST)
 * 
 * left : left child node
 * right : right child node
 * value : value of node (also called as key or data)
 * is_dynamic : identifier for dynamic or not, must be set to 0 (false) or 1 (true)
 * (recommended not to change directly)
 * 
 * except of root node, dynamic allocation of node by bst_insert() function is highly recommeded
 * direct modification of left, right property can cause unintended behavior
*/
struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    int value;
    unsigned char is_dynamic;
};

/**
 * traverse in pre-order
 * 
 * root : root node of bst
*/
void traverse_pre_order_recursive(struct bst_node *node);

/**
 * traverse in in-order
 * 
 * root : root node of bst
*/
void traverse_in_order_recursive(struct bst_node *node);

/**
 * traverse in post-order
 * 
 * root : root node of bst
*/
void traverse_post_order_recursive(struct bst_node *node);

/**
 * search value in bst
 * return pointer of founded node
 * if no value exists, return NULL
 * 
 * root : root node of bst
 * value : value to search
*/
struct bst_node* bst_search(struct bst_node *root, const int value);

/**
 * insert value in bst
 * return pointer of newly assigned node or null pointer
 * if the value already exists, do nothing
 * 
 * if root is NULL, initialize bst tree - create new root node
 * 
 * root : root node of bst
 * value : value to insert
*/
struct bst_node *bst_insert(struct bst_node *root, const int value);

/**
 * delete value in bst
 * if the value not exists, do nothing
 * if the root node does not have any child node, release the root node
 * 
 * root : root node of bst
 * value : value to delete
*/
void bst_delete(struct bst_node *root, const int value);

#endif