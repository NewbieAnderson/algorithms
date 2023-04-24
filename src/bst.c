#include "bst.h"

void traverse_pre_order_recursive(struct bst_node *node)
{
    if (node == NULL)
        return;
    printf("%d\n", node->value);
    traverse_pre_order_recursive(node->left);
    traverse_pre_order_recursive(node->right);
}

void traverse_in_order_recursive(struct bst_node *node)
{
    if (node == NULL)
        return;
    traverse_in_order_recursive(node->left);
    printf("%d\n", node->value);
    traverse_in_order_recursive(node->right);
}

void traverse_post_order_recursive(struct bst_node *node)
{
    traverse_post_order_recursive(node->left);
    printf("%d\n", node->value);
    traverse_post_order_recursive(node->right);
}

struct bst_node *bst_search(struct bst_node *root, const int value)
{
    struct bst_node *node = root;
    while (node) {
        if (node->value == value)
            return node;
        node = node->value > value ? node->left : node->right;
    }
    return NULL;
}

struct bst_node *bst_insert(struct bst_node *root, const int value)
{
    struct bst_node *node = root;
    struct bst_node *new_node = malloc(sizeof(struct bst_node));
    if (node == NULL) {
        node = malloc(sizeof(struct bst_node));
        if (root == NULL)
            return NULL;
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        node->is_dynamic = 1;
        return node;
    }
    if (new_node == NULL || node == NULL)
        return NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = value;
    new_node->is_dynamic = 1;
    while (node) {
        if (node->value > value) {
            if (node->left != NULL) {
                node = node->left;
            } else {
                node->left = new_node;
                break;
            }
        } else if (node->value < value) {
            if (node->right != NULL) {
                node = node->right;
            } else {
                node->right = new_node;
                break;
            }
        } else {
            free(new_node);
            new_node = NULL;
            return new_node;
        }
    }
    return new_node;
}

void bst_delete(struct bst_node *root, const int value)
{
    struct bst_node *node = root;
    struct bst_node *parent_node = NULL;
    struct bst_node *subtree_node = NULL;
    struct bst_node *parent_subtree_node = NULL;
    while (node != NULL && node->value != value) {
        parent_node = node;
        node = node->value > value ? node->left : node->right;
    }
    if (node == NULL)
        return;
    if (node->left != NULL && node->right != NULL) {
        subtree_node = node->left;
        while (subtree_node->right) {
            parent_subtree_node = subtree_node;
            subtree_node = subtree_node->right;
        }
        node->value = subtree_node->value;
        if (node->is_dynamic)
            free(subtree_node);
        subtree_node = NULL;
    } else if (node->left != NULL) {
        if (parent_node->left == node)
            parent_node->left = node->left;
        else if (parent_node->right == node)
            parent_node->right = node->left;
        if (node->is_dynamic)
            free(node);
        node = NULL;
    } else if (node->right != NULL) {
        if (parent_node->left == node)
            parent_node->left = node->right;
        else if (parent_node->right == node)
            parent_node->right = node->right;
        if (node->is_dynamic)
            free(node);
        node = NULL;
    } else {
        if (parent_node != NULL) {
            if (parent_node->left == node)
                parent_node->left = NULL;
            else if (parent_node->right == node)
                parent_node->right = NULL;
        }
        if (node->is_dynamic)
            free(node);
        node = NULL;
        return;
    }
    if (parent_subtree_node != NULL) {
        if (parent_subtree_node->left == subtree_node)
            parent_subtree_node->left = NULL;
        else if (parent_subtree_node->right == subtree_node)
            parent_subtree_node->right = NULL;
    }
}