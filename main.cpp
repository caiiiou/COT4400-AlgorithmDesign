#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "merge_sort.h"
#include "activity_selection.h"
#include "knapsack.h"

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
        // Generate random array of size n
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();

        double elapsed = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << n << "\t\t" << elapsed << " ms" << std::endl;
    }

    std::cout << std::endl;

    // ========================================
    // TODO: Activity Selection tests go here
    // ========================================
    std::cout << "========================================" << std::endl;
    std::cout << "  ACTIVITY SELECTION (Greedy)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  [Not yet implemented]" << std::endl << std::endl;

    // ========================================
    // TODO: Knapsack tests go here
    // ========================================
    std::cout << "========================================" << std::endl;
    std::cout << "  0/1 KNAPSACK (Dynamic Programming)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  [Not yet implemented]" << std::endl << std::endl;

    return 0;
}
