#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// Merges two sorted halves of arr: [left..mid] and [mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right);

// Recursively splits and sorts array using merge sort
void mergeSort(std::vector<int>& arr, int left, int right);

#endif
