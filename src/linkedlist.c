#include "./linkedlist.h"

void retrieve_all(struct node *entry, void *(*routine)(struct node *current))
{
    struct node *current_node;
    if (entry == NULL)
        return;
    for (current_node = entry; LOOP_CONDITION(current_node); current_node = current_node->next) {
        if (routine != NULL)
            routine(current_node);
        else
            printf("%d\n", entry->value);
    }
}

int* const at(struct node *entry, int index)
{
    int pos = 0;
    struct node *current_node = entry;
    if (index < 0 || entry == NULL)
        return NULL;
    if (index == 0)
        return entry;
    for (; pos < index && LOOP_CONDITION(current_node); current_node = current_node->next)
        ++pos;
    if (pos != index)
        return NULL;
    return current_node;
}

int* const find_by_value(struct node *entry, int value)
{
    struct node *current_node;
    if (entry == NULL)
        return NULL;
    for (current_node = entry; LOOP_CONDITION(current_node); current_node = current_node->next) {
    }
    return 0;
}

int insert_by_index(struct node *entry, int value, int index)
{
    return 0;
}

int delete_by_index(struct node *entry, int index)
{
    return 0;
}

int delete_by_value(struct node *entry, int value)
{
    return 0;
}

int push(struct node *entry, int value)
{
    return 0;
}

void pop(struct node *entry)
{
}