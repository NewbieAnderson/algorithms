#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define MAX_ITEM_SIZE 256

#include <stdlib.h>
#include <stddef.h>

struct item {
    char bytes[MAX_ITEM_SIZE];
    int length;
};

struct ring_buffer {
    struct item *buf;
    int size;
    int capacity;
    int read_ptr;
    int write_ptr;
};

int init_ring_buffer(struct ring_buffer *rbuf, const int capacity);

void insert_item(struct ring_buffer *rbuf, struct item value);

struct item remove_item(struct ring_buffer *rbuf);

const struct item *get_item(struct ring_buffer *rbuf, int index);

void retrieve(struct ring_buffer *rbuf);

void delete_ring_buffer(struct ring_buffer *rbuf);

void clear_buffer(struct ring_buffer *rbuf);

#endif