#include "bst.h"

void traverse_pre_order_recursive(const struct bst_node *const node)
{
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    traverse_pre_order_recursive(node->left);
    traverse_pre_order_recursive(node->right);
}

void traverse_in_order_recursive(const struct bst_node *const node)
{
    if (node == NULL)
        return;
    traverse_in_order_recursive(node->left);
    printf("%d\n", node->data);
    traverse_in_order_recursive(node->right);
}

void traverse_post_order_recursive(const struct bst_node *const node)
{
    traverse_post_order_recursive(node->left);
    printf("%d\n", node->data);
    traverse_post_order_recursive(node->right);
}

const struct bst_node *const bst_search(const struct bst_node *const root, const int data)
{
    const struct bst_node *node = root;
    while (node) {
        if (node->data == data)
            return node;
        node = node->data > data ? node->left : node->right;
    }
    return NULL;
}

int bst_insert(const struct bst_node *const root, const int data)
{
    struct bst_node *node = root;
    struct bst_node *new_node = malloc(sizeof(struct bst_node));
    if (new_node == NULL || node == NULL)
        return -1;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    new_node->is_dynamic = 1;
    while (node) {
        if (node->data > data) {
            if (node->left != NULL) {
                node = node->left;
            } else {
                node->left = new_node;
                break;
            }
        } else if (node->data < data) {
            if (node->right != NULL) {
                node = node->right;
            } else {
                node->right = new_node;
                break;
            }
        } else {
            free(new_node);
            new_node = NULL;
            return -1;
        }
    }
    return 0;
}

void bst_delete(const struct bst_node *const root, const int data)
{
    struct bst_node *node = root;
    struct bst_node *parent_node = NULL;
    struct bst_node *subtree_node = NULL;
    struct bst_node *parent_subtree_node = NULL;
    while (node != NULL && node->data != data) {
        parent_node = node;
        node = node->data > data ? node->left : node->right;
    }
    if (node == NULL)
        return;
    if (node->left != NULL && node->right != NULL) {
        subtree_node = node->left;
        while (subtree_node->right) {
            parent_subtree_node = subtree_node;
            subtree_node = subtree_node->right;
        }
        node->data = subtree_node->data;
        free(subtree_node);
        subtree_node = NULL;
    } else if (node->left != NULL) {
        if (parent_node->left == node)
            parent_node->left = node->left;
        else if (parent_node->right == node)
            parent_node->right = node->left;
        free(node);
        node = NULL;
    } else if (node->right != NULL) {
        if (parent_node->left == node)
            parent_node->left = node->right;
        else if (parent_node->right == node)
            parent_node->right = node->right;
        free(node);
        node = NULL;
    } else {
        if (parent_node != NULL) {
            if (parent_node->left == node)
                parent_node->left = NULL;
            else if (parent_node->right == node)
                parent_node->right = NULL;
        }
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