#include <iostream>
#include <vector>
#include <chrono>

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

// Helper to print a vector
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        std::cout << arr[i];
        if (i < (int)arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Runs merge sort on a test case, prints before/after, and records time
void testMergeSort(const std::string& label, std::vector<int> arr) {
    std::cout << label << std::endl;
    std::cout << "  Input:  ";
    printArray(arr);

    auto start = std::chrono::high_resolution_clock::now();
    if (!arr.empty())
        mergeSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsed = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "  Output: ";
    printArray(arr);
    std::cout << "  Time:   " << elapsed << " ms" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  MERGE SORT (Divide & Conquer)" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // Test 1: Random array
    testMergeSort("Test 1 - Random array:", {38, 27, 43, 3, 9, 82, 10});

    // Test 2: Already sorted array
    testMergeSort("Test 2 - Already sorted:", {1, 2, 3, 4, 5, 6, 7});

    // Test 3: Reverse sorted array
    testMergeSort("Test 3 - Reverse sorted:", {7, 6, 5, 4, 3, 2, 1});

    // Test 4: Edge case - empty array
    testMergeSort("Test 4 - Empty array:", {});

    // Test 5: Edge case - single element
    testMergeSort("Test 5 - Single element:", {42});

    // Experimental evaluation - increasing input sizes
    std::cout << "--- Experimental Evaluation ---" << std::endl;
    std::cout << "Input Size\tTime (ms)" << std::endl;

    std::vector<int> sizes = {10, 100, 1000, 10000};
    for (int n : sizes) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();

        double elapsed = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << n << "\t\t" << elapsed << " ms" << std::endl;
    }

    return 0;
}
