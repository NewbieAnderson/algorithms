#include <stdio.h>
#include "../src/bsearch.h"

int main(void)
{
    int arr1[5] = { 1, 2, 3, 4, 5 };
    int arr2[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    printf("arr1 = [ 1, 2, 3, 4, 5 ]\n"
            "arr2 = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 ]\n"
            "index of \'2\' in arr1 : %d\n"
            "index of \'4\' in arr2 : %d\n",
            bsearch(arr1, 5, 2), bsearch(arr2, 16, 4));
    return 0;
}