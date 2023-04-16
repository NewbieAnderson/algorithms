#ifndef SORTS_H
#define SORTS_H

#define ARR_IS_EMPTY                    -1
#define ARR_LENGTH_IS_NEGATIVE          -2
#define QUICK_SORT_INCORRECT_INDEXING   -5

/**
 * Bubble Sorting Algorithm.
 * 
 * Average Time Complexity is O(N^2).
 * In the worst case, Time Complexity is O(N^2).
 * Space Complexity is O(1).
 * Stability is guaranteed.
 * 
 * Arguments
 * arr : array of integer
 * n : length of array
 * 
 * Returns the number of calculations performed.
*/
int bubble_sort(int arr[], const int n);

/**
 * Selection Sorting Algorithm.
 * 
 * Average Time Complexity is O(N^2).
 * In the worst case, Time Complexity is O(N^2).
 * Space Complexity is O(1).
 * Stability is not guaranteed.
 * 
 * Arguments
 * arr : array of integer
 * n : length of array
 * 
 * Returns the number of calculations performed.
*/
int selection_sort(int arr[], const int n);

/**
 * Insert Sorting Algorithm.
 * 
 * Average Time Complexity is O(N^2).
 * In the worst case, Time Complexity is O(N^2).
 * Space Complexity is O(1).
 * Stability is guaranteed.
 * 
 * Arguments
 * arr : array of integer
 * n : length of array
 * 
 * Returns the number of calculations performed.
*/
int insertion_sort(int arr[], const int n);

/**
 * Quick Sorting Algorithm.
 * 
 * Average Time Complexity is O(N log N).
 * In the worst case, Time Complexity is O(N^2).
 * Space Complexity is O(log N).
 * Stability is not guaranteed.
 * 
 * Arguments
 * arr : array of integer
 * n : length of array
 * l_index : The left index value - must be set to
 *           the first index value of the element to be sorted when called.
 * r_index : The right index value - must be set to
 *           the last index value of the element to be sorted when called.
 * 
 * Returns the number of calculations performed.
*/
int quick_sort_recursive(int arr[], const int n, int l_index, int r_index);

#endif