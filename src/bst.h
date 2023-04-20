#ifndef BST_H
#define BST_H

#include <stdlib.h>

#define PRE_ORDER_TRAVERSAL  1
#define IN_ORDER_TRAVERSAL   2
#define POST_ORDER_TRAVERSAL 3

struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    int data;
    unsigned char is_dynamic;
};

void bst_retrieve(const struct bst_node *const root, const unsigned char traverse_type);

const struct bst_node *const bst_search(const struct bst_node *const root, const int data);

int bst_insert(const struct bst_node *const root, const int data);

void bst_delete(const struct bst_node *const root, const int data);

int arr_to_bst(const struct bst_node *const root, int arr[], int len);

int bst_to_arr(const struct bst_node *const root, int arr[], int len);

#endif