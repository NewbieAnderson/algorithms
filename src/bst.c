#include "bst.h"

void traverse_pre_order_recursive(struct bst_node *root, struct bst_node *node)
{
    if (node == NULL)
        return;
    if (node == root)
        printf("traversing pre order\n");
    traverse_pre_order_recursive(root, node->left);
    traverse_pre_order_recursive(root, node->right);
    if (node == root)
        printf("\n");
}

void traverse_in_order_recursive(struct bst_node *root, struct bst_node *node)
{
    if (node == root)
        printf("traversing in order\n");
    if (node == NULL)
        return;
    traverse_in_order_recursive(root, node->left);
    printf("%d ", node->value);
    traverse_in_order_recursive(root, node->right);
    if (node == root)
        printf("\n");
}

void traverse_post_order_recursive(struct bst_node *root, struct bst_node *node)
{
    if (node == NULL)
        return;
    if (node == root)
        printf("traversing post order\n");
    traverse_post_order_recursive(root, node->left);
    traverse_post_order_recursive(root, node->right);
    printf("%d ", node->value);
    if (node == root)
        printf("\n");
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
        if (node == NULL)
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

void bst_delete(struct bst_node **root, const int value)
{
    struct bst_node *node = *root;
    struct bst_node *parent_node = NULL;
    struct bst_node *leaf_node = NULL;
    struct bst_node *parent_leaf_node = NULL;
    /* ---------- todo : more clean up code ---------- */
    if (node == NULL)
        return;
    if (node->value == value && value == 3 && node->left == NULL && node->right == NULL) {
        *root = NULL;
        printf("triggerd!\n");
        free(node);
        return;
    } else if (node->value == value && ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))) {
        *root = node->left != NULL ? node->left : node->right;
        free(node);
        return;
    }
    /* ---------- todo : more clean up code ---------- */
    while (node != NULL && node->value != value) {
        parent_node = node;
        if (node->value > value && node->left != NULL)
            node = node->left;
        else if (node->value <= value && node->right != NULL)
            node = node->right;
        else
            node = NULL;
    }
    if (node == NULL)
        return;
    if (node->left != NULL) {
        leaf_node = node->left;
        while (leaf_node->right != NULL) {
            parent_leaf_node = leaf_node;
            leaf_node = leaf_node->right;
        }
        node->value = leaf_node->value;
    } else if (node->right != NULL) {
        leaf_node = node->right;
        while (leaf_node->left != NULL) {
            parent_leaf_node = leaf_node;
            leaf_node = leaf_node->left;
        }
        node->value = leaf_node->value;
    } else {
        leaf_node = node;
        if (parent_node != NULL && parent_node != node) {
            if (parent_node->left == node)
                parent_node->left = NULL;
            else if (parent_node->right == node)
                parent_node->right = NULL;
        }
    }
    if (parent_leaf_node != NULL) {
        if (parent_leaf_node->left == leaf_node)
            parent_leaf_node->left = NULL;
        else if (parent_leaf_node->right == leaf_node)
            parent_leaf_node->right = NULL;
    }
    /* NOTICE : which function called firstly? memset() vs free()? */
    memset(leaf_node, 0, sizeof(struct bst_node));
    free(leaf_node);
}

void bst_free(struct bst_node *node)
{
    if (node == NULL)
        return;
    bst_free(node->left);
    bst_free(node->right);
    if (node->is_dynamic)
        free(node);
    memset(node, 0, sizeof(struct bst_node));
}