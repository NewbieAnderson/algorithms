#include "../src/bst.h"

int main(void)
{
    struct bst_node *root = bst_insert(NULL, 32);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 3);
    bst_insert(root, 1);
    bst_search(root, 3);
    traverse_in_order_recursive(root);
    bst_delete(root, 32);
    bst_delete(root, 5);
    bst_delete(root, 2);
    bst_delete(root, 3);
    bst_delete(root, 1);
    bst_delete(root, 3);
    return 0;
}