#ifndef BST_H
#define BST_H

#include <stdlib.h>

struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    int data;
    unsigned char is_dynamic;
};

void traverse_pre_order_recursive(const struct bst_node *const node);

void traverse_in_order_recursive(const struct bst_node *const node);

void traverse_post_order_recursive(const struct bst_node *const node);

const struct bst_node *const bst_search(const struct bst_node *const root, const int data);

int bst_insert(const struct bst_node *const root, const int data);

void bst_delete(const struct bst_node *const root, const int data);

#endif