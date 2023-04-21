#include "bst.h"

void bst_retrieve(const struct bst_node *const root, const unsigned char traverse_type)
{
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
}

int arr_to_bst(const struct bst_node *const root, int arr[], int len)
{
    return 0;
}

int bst_to_arr(const struct bst_node *const root, int arr[], int len)
{
    return 0;
}