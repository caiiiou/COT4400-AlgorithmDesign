#include <vector>
using namespace std;

// Merge sort uses divide and conquer to split, sort, and merge.
// Time complexity: O(n log n), space complexity: O(n).
// Merge two sorted halves
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    // i scans the left half and j scans the right half.
    int i = left, j = mid + 1;

    // Compare both halves and append the smaller value each time.
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    // Copy any remaining values from the left half.
    while (i <= mid) temp.push_back(arr[i++]);
    // Copy any remaining values from the right half.
    while (j <= right) temp.push_back(arr[j++]);

    // Copy the merged result back into the original array.
    for (int k = 0; k < (int)temp.size(); k++)
        arr[left + k] = temp[k];
}

// Recursive merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    // Base case: one or zero elements are already sorted.
    if (left >= right) return;
    // Compute the midpoint this way to avoid overflow.
    int mid = left + (right - left) / 2;
    // Recursively sort the left half.
    mergeSort(arr, left, mid);
    // Recursively sort the right half.
    mergeSort(arr, mid + 1, right);
    // Merge the two sorted halves.
    merge(arr, left, mid, right);
}
