#ifndef BSEARCH_C
#define BSEARCH_C

#include <stddef.h>

/**
 * binary search algorithm
 * returns index of value or not exists, returns -1
 * 
 * arr : array that expected to be found value
 * len : length of array, passing the wrong length can cause undefined behavior
 * value : value to be found
*/
const int bsearch(const int arr[], const int len, const int value);

#endif