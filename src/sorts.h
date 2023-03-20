#ifndef SORTS_H
#define SORTS_H

#define ARR_IS_EMPTY            -1
#define ARR_LENGTH_IS_NEGATIVE  -2

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
int bubbleSort(int arr[], const int n);

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
int selectionSort(int arr[], const int n);

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
int insertSort(int arr[], const int n);

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
 * lIndex : The left index value - must be set to 
 *          the first index value of the element to be sorted when called.
 * rIndex : The right index value - must be set to 
 *          the last index value of the element to be sorted when called.
 * 
 * Returns the number of calculations performed.
*/
int quickSortRecur(int arr[], const int n, int lIndex, int rIndex);

#endif