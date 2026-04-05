#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <utility>
using namespace std;

void mergeSort(vector<int>& arr, int left, int right);
vector<int> activitySelection(vector<pair<int,int>>& activities);
int knapsack(vector<int>& weights, vector<int>& values, int capacity);

void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;
}

// Times any function and returns elapsed ms
double timeIt(function<void()> fn) {
    auto start = chrono::high_resolution_clock::now();
    fn();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

void testMergeSort(string label, vector<int> arr) {
    cout << label << endl;
    cout << "  Input:  "; printArray(arr);

    double ms = timeIt([&]() {
        if (!arr.empty()) mergeSort(arr, 0, arr.size() - 1);
    });

    cout << "  Output: "; printArray(arr);
    cout << "  Time:   " << ms << " ms\n\n";
}

int main() {
    cout << "MERGE SORT (Divide & Conquer)\n\n";

    testMergeSort("Test 1 - Random array:", {38, 27, 43, 3, 9, 82, 10});
    testMergeSort("Test 2 - Already sorted:", {1, 2, 3, 4, 5, 6, 7});
    testMergeSort("Test 3 - Reverse sorted:", {7, 6, 5, 4, 3, 2, 1});
    testMergeSort("Test 4 - Empty array:", {});
    testMergeSort("Test 5 - Single element:", {42});

    cout << "Experimental Evaluation\n";
    cout << "Input Size\tTime (ms)\n";
    for (int n : {10, 100, 1000, 10000}) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

        double ms = timeIt([&]() { mergeSort(arr, 0, arr.size() - 1); });
        cout << n << "\t\t" << ms << " ms\n";
    }
    cout << endl;

    // TODO: Activity Selection tests
    // TODO: Knapsack tests

    return 0;
}
