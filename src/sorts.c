#include "./sorts.h"

int bubble_sort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int computation_count = 0;
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
            ++computation_count;
        }
    }
    return computation_count;
}

int selection_sort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int computation_count = 0;
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
            ++computation_count;
        }
    }
    return computation_count;
}

int insertion_sort(int arr[], const int n)
{
    int i;
    int j;
    int temp;
    int target;
    int computation_count = 0;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    for (i = 1; i < n; ++i) {
        target = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > target; --j) {
            arr[j + 1] = arr[j];
            ++computation_count;
        }
        arr[j + 1] = target;
    }
    return computation_count;
}

int quick_sort_recursive(int arr[], const int n, int l_index, int r_index)
{
    int i;
    int j;
    int temp;
    int pivot = l_index;
    int computation_count = 0;
    if (!arr)
        return ARR_IS_EMPTY;
    else if (n <= 0)
        return ARR_LENGTH_IS_NEGATIVE;
    else if (r_index > n)
        return QUICK_SORT_INCORRECT_INDEXING;
    else if (l_index >= r_index)
        return 0;
    for (i = pivot; i < r_index; ++i) {
        if (arr[r_index] > arr[i]) {
            temp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = temp;
            ++pivot;
        }
        ++computation_count;
    }
    temp = arr[pivot];
    arr[pivot] = arr[r_index];
    arr[r_index] = temp;
    return computation_count + quick_sort_recursive(arr, n, l_index, pivot - 1) + quick_sort_recursive(arr, n, pivot + 1, r_index);
}