#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYYE_SIZE 256

/**
 * single data unit to be stored into ring buffer
 * expressed as an array of bytes
 * 
 * bytes : contents of the data
 * length : length of the data
*/
struct item {
    char bytes[MAX_BYYE_SIZE];
    int len;
};

/**
 * Ring Buffer (rbuf)
 * store datas as circular FIFO(First In First Out) structure
 * genarlly, used as a requests queue for UDP packet or REST API to be processed
 * these all member variables aren't recommeded to change directly (recommeded as read-only)
 * 
 * buf : buffer of ring buffer - store data as array of bytes, be assigned dynamically
 * size : number of currently stored elements
 * capacity : entire size of queue - genarlly, immutable recommeded
 * read_ptr : position of read pointer, first place to process data and not always fixed by zero
 * write_ptr : position of write pointer, first place to be stored data
 * (NOTICE : read_ptr and write_ptr aren't meaning C pointer - that just integer index indicator)
*/
struct ring_buffer {
    struct item *buf;
    int size;
    int capacity;
    int read_ptr;
    int write_ptr;
};

/**
 * initialize ring buffer
 * performs very large-scale dynamic memory allocation through the malloc() function
 * recommended to run in the beginning stage of program execution
 * must called before using ring buffer
 * 
 * rbuf : ring buffer
 * capacity : entire size of queue
*/
int init_ring_buffer(struct ring_buffer *rbuf, const int capacity);

/**
 * insert new item after last element
 * by increasing write_ptr of ring buffer, working as 'insert'
 * if write_ptr is 'capacity - 1', it is set back to '0'
 * 
 * rbuf : ring buffer
 * value : element that want to be stored in
*/
void insert_item(struct ring_buffer *rbuf, struct item value);

/**
 * remove the first of element
 * by increasing read_ptr of ring buffer, working as 'remove'
 * if read_ptr is 'capacity - 1', it is set back to '0'
 * returns element
 * 
 * rbuf : ring buffer
*/
struct item remove_item(struct ring_buffer *rbuf);

/**
 * retrieve all valid elements of ring buffer
 * 
 * rbuf : ring buffer
*/
void retrieve(struct ring_buffer *rbuf);

/**
 * clear all buffer
 * set read_ptr, write_ptr, size to 0
 * 
 * rbuf : ring buffer
*/
void clear_buffer(struct ring_buffer *rbuf);

/**
 * release and delete memory assigned into buffer
 * must called ring buffer no more used anymore
 * 
 * rbuf : ring buffer
*/
void delete_ring_buffer(struct ring_buffer *rbuf);

#endif