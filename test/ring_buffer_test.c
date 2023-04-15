#include "../src/ring_buffer.h"

#include <string.h>

// gcc -o ring_buffer_test ring_buffer_test.c ../src/ring_buffer.c

int main(void)
{
    struct ring_buffer rbuf;
    init_ring_buffer(&rbuf, 5);
    insert_item(&rbuf, (struct item){
        "hello ring buffer1",
        strlen("hello ring buffer1")
    });
    insert_item(&rbuf, (struct item){
        "hello ring buffer2",
        strlen("hello ring buffer2")
    });
    insert_item(&rbuf, (struct item){
        "hello ring buffer3",
        strlen("hello ring buffer3")
    });
    insert_item(&rbuf, (struct item){
        "hello ring buffer4",
        strlen("hello ring buffer4")
    });
    insert_item(&rbuf, (struct item){
        "hello ring buffer5",
        strlen("hello ring buffer5")
    });
    retrieve(&rbuf);
    printf("\n");
    remove_item(&rbuf);
    remove_item(&rbuf);
    retrieve(&rbuf);
    clear_buffer(&rbuf);
    retrieve(&rbuf);
    delete_ring_buffer(&rbuf);
    return 0;
}