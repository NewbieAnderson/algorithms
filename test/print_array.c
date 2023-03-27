#include <stdio.h>

void print_arr(int arr[], int arrLength, int i, int j, int flag) {
    int k;

    if (!arr || arrLength <= 0) {
        return;
    }

    //printf("(j - 1 = \033[0;31m%d\033[0m, j = \033[0;32m%d\033[0m), [ ", i, j);
    printf("[ ");
    for (k = 0; k < arrLength; k++) {
        if ((k == i || k == j) && flag == 0) {
            printf("\033[0;31m%d\033[0m, ", arr[k]);
        } else if ((k == i || k == j) && flag == 1) {
            printf("\033[0;32m%d\033[0m, ", arr[k]);
        } else {
            printf("%d, ", arr[k]);
        }
    }
    printf("\b\b ]");
}