#include "ring_buffer.h"

int init_ring_buffer(struct ring_buffer *rbuf, const int capacity)
{
    if (capacity <= 0)
        return -1;
    rbuf->buf = calloc(capacity, sizeof(struct item));
    if (rbuf->buf == NULL)
        return -1;
    rbuf->size = 0;
    rbuf->capacity = capacity;
    rbuf->read_ptr = 0;
    rbuf->write_ptr = 0;
    return 0;
}

void insert_item(struct ring_buffer *rbuf, struct item value)
{
    if (rbuf->size >= rbuf->capacity) {
        printf("insert_item() : cannot add more items.\n(bytes : \"%s\")\n", value.bytes);
        return;
    }
    ++rbuf->size;
    rbuf->buf[rbuf->write_ptr] = value;
    rbuf->write_ptr = (rbuf->write_ptr + 1) % rbuf->capacity;
}

struct item remove_item(struct ring_buffer *rbuf)
{
    const int read_ptr = rbuf->read_ptr;
    if (rbuf->size <= 0) {
        printf("remove_item() : cannot remove more!\n");
        return (struct item){ { 0, }, 0 };
    }
    --rbuf->size;
    rbuf->read_ptr = (read_ptr + 1) % rbuf->capacity;
    return rbuf->buf[read_ptr];
}

void retrieve(struct ring_buffer *rbuf)
{
    int read = rbuf->read_ptr;
    int write = rbuf->write_ptr;
    if (rbuf->size > 0) {
        printf("%s\n", rbuf->buf[read].bytes);
        read = (read + 1) % rbuf->capacity;
    }
    while (read != write) {
        printf("%s\n", rbuf->buf[read].bytes);
        read = (read + 1) % rbuf->capacity;
    }
}

void clear_buffer(struct ring_buffer *rbuf)
{
    rbuf->read_ptr = 0;
    rbuf->write_ptr = 0;
    rbuf->size = 0;
    memset(rbuf->buf, 0, sizeof(struct item));
}

void delete_ring_buffer(struct ring_buffer *rbuf)
{
    free(rbuf->buf);
    rbuf->buf = NULL;
}