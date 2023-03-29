#include <stdio.h>
#include "../src/sorts.h"

/**
 * Compile Script : gcc -o test_sorting test_sorting.c ../src/sorts.c
*/
int main(void)
{
    int arr[4][16] = {
        { 1, 11, 5, 2, 9, 4, 8, 14, 6, 7, 3, 0, 15, 12, 13, 10 },
        { 1, 11, 5, 2, 9, 4, 8, 14, 6, 7, 3, 0, 15, 12, 13, 10 },
        { 1, 11, 5, 2, 9, 4, 8, 14, 6, 7, 3, 0, 15, 12, 13, 10 },
        { 1, 11, 5, 2, 9, 4, 8, 14, 6, 7, 3, 0, 15, 12, 13, 10 },
    };
    const int N = 16;
    int computationCount;
    int i;
    printf("Before : ");
    for (i = 0; i < N; ++i)
        printf("%d ", arr[3][i]);
    printf("\n\nBubble Sort    = %d times\n"
            "Selection Sort = %d times\n"
            "Insert Sort    = %d times\n"
            "Quick Sort     = %d times\n\n"
            "After  : ",
            bubble_sort(arr[0], N),
            selection_sort(arr[1], N),
            insertion_sort(arr[2], N),
            quick_sort_recursive(arr[3], N, 0, N - 1));
    for (i = 0; i < N; ++i)
        printf("%d ", arr[3][i]);
    printf("\n\n");
    return 0;
}