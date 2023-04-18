#include "bsearch.h"

const int bsearch(const int arr[], const int len, const int value) {
    int left = 0;
    int right = len - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}