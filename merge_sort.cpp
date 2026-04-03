#include "merge_sort.h"

// Merges two sorted subarrays of arr:
// First subarray: arr[left..mid]
// Second subarray: arr[mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Create temporary arrays for left and right halves
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0; // index for left half
    int j = 0; // index for right half
    int k = left; // index for merged array

    // Compare elements from both halves and place the smaller one
    while (i < (int)leftArr.size() && j < (int)rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left half
    while (i < (int)leftArr.size()) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right half
    while (j < (int)rightArr.size()) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursively divides the array in half, sorts each half, then merges them
void mergeSort(std::vector<int>& arr, int left, int right) {
    // Base case: subarray has 0 or 1 elements
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Recursively sort left half
    mergeSort(arr, left, mid);

    // Recursively sort right half
    mergeSort(arr, mid + 1, right);

    // Merge the two sorted halves
    merge(arr, left, mid, right);
}
