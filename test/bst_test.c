#include "../src/bst.h"

int main(void)
{
    struct bst_node *root = bst_insert(NULL, 32);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 3);
    bst_insert(root, 1);
    bst_search(root, 3);
    traverse_pre_order_recursive(root, root);
    traverse_in_order_recursive(root, root);
    traverse_post_order_recursive(root, root);
    printf("try to delete node 32\n");
    bst_delete(&root, 32);
    traverse_in_order_recursive(root, root);
    printf("try to delete node 1\n");
    bst_delete(&root, 1);
    printf("try to delete node 5\n");
    bst_delete(&root, 5);
    traverse_in_order_recursive(root, root);
    printf("try to delete node 5\n");
    bst_delete(&root, 5);
    printf("try to delete node 2\n");
    bst_delete(&root, 2);
    printf("try to delete node 5\n");
    bst_delete(&root, 5);
    traverse_in_order_recursive(root, root);
    printf("try to delete node 3\n");
    bst_delete(&root, 3);
    printf("try to delete node 12\n");
    bst_delete(&root, 12); /* accessing invalid root node. */
    traverse_in_order_recursive(root, root);
    printf("try to delete node 3\n");
    bst_delete(&root, 3);
    traverse_in_order_recursive(root, root);
    return 0;
}