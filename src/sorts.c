#include "./sorts.h"

int bubbleSort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int computationCount = 0;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            ++computationCount;
        }
    }
    return computationCount;
}

int selectionSort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int computationCount = 0;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            ++computationCount;
        }
    }
    return computationCount;
}

int insertSort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int target;
    int computationCount = 0;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    for (i = 1; i < n; ++i) {
        target = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > target; --j) {
            arr[j + 1] = arr[j];
            ++computationCount;
        }
        arr[j + 1] = target;
    }
    return computationCount;
}

int quickSortRecur(int arr[], const int n, int lIndex, int rIndex)
{
    int i;
    int j;
    int temp;
    int computationCount = 0;
    int lPivot = lIndex;
    int rPivot = rIndex;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    else if (rIndex > n)
        return -3;
    else if (rIndex - lIndex <= 0)
        return 1;
    for (i = lPivot; i < rPivot; ++i) {
        if (arr[rPivot] > arr[i]) {
            temp = arr[lPivot];
            arr[lPivot] = arr[i];
            arr[i] = temp;
            ++lPivot;
        }
        ++computationCount;
    }
    temp = arr[lPivot];
    arr[lPivot] = arr[rPivot];
    arr[rPivot] = temp;
    return computationCount + quickSortRecur(arr, n, lIndex, lPivot - 1) + quickSortRecur(arr, n, lPivot + 1, rIndex);
}