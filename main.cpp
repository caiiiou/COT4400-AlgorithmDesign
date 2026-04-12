#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <utility>
#include <cstdlib>
using namespace std;

// Forward declarations for sorting, greedy, and DP functions defined in other files
void mergeSort(vector<int>& arr, int left, int right);
void activitySelection(vector<int>& start, vector<int>& finish, bool print = true);
int knapsack(vector<int>& weights, vector<int>& values, int capacity);

// Helper to display a vector
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

// Runs merge sort on an array, prints before/after and timing, and skips empty input
void testMergeSort(string label, vector<int> arr) {
    cout << label << endl;
    cout << "  Input:  "; printArray(arr);

    double ms = timeIt([&]() {
        if (!arr.empty()) mergeSort(arr, 0, arr.size() - 1);
    });

    cout << "  Output: "; printArray(arr);
    cout << "  Time:   " << ms << " ms\n\n";
}


// Runs activity selection and prints the start/finish times with timing
void testActivitySelection(string label, vector<int> start, vector<int> finish) {
    cout << label << endl;

    cout << "  Start Times:  "; printArray(start);
    cout << "  Finish Times: "; printArray(finish);

    double ms = timeIt([&]() {
        activitySelection(start, finish, true);
    });

    cout << "  Time:         " << ms << " ms\n\n";
}

// Runs 0/1 knapsack and prints weights, values, capacity, result, and timing
void testKnapsack(string label, vector<int> weights, vector<int>values, int capacity){
    cout << label << endl;

    cout << " Weights:  "; printArray(weights);
    cout << " Values:  "; printArray(values);
    cout << " Capacity:   " << capacity << endl;

    int result = 0;
    double ms = timeIt([&]() {
        result = knapsack(weights, values, capacity);
    });

    cout << "  Max Value: " << result << endl;
    cout << "  Time:      " << ms << " ms\n\n";
}

int main() {
    cout << "MERGE SORT (Divide & Conquer)\n\n";

    // Runs correctness tests on edge cases, then benchmarks increasing random input sizes
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

    
    // Runs correctness tests, then benchmarks random activities with random starts and durations
    cout << "ACTIVITY SELECTION (Greedy Algorithm)\n\n";

    testActivitySelection("Test 1 - Basic case:", {1, 3, 0, 5, 8, 5}, {2, 4, 6, 7, 9, 9});
    testActivitySelection("Test 2 - Single activity:", {2}, {3});
    testActivitySelection("Test 3 - Empty input:", {}, {});
    testActivitySelection("Test 4 - Non-overlapping:", {1, 3, 5, 7}, {2, 4, 6, 8});
    testActivitySelection("Test 5 - Overlapping case:", {1, 2, 3, 4}, {5, 6, 7, 8});
    
    cout << "Experimental Evaluation\n";
    cout << "Input Size\tTime (ms)\n";
    for (int n : {10, 100, 1000, 5000}) 
    {
        vector<int> start(n), finish(n);
    
        for (int i = 0; i < n; i++) 
        {
            start[i] = rand() % 10000;
            finish[i] = start[i] + (rand() % 50 + 1);
        }
    
        double ms = timeIt([&]() {
            activitySelection(start, finish, false);
        });
    
        cout << n << "\t\t" << ms << " ms\n";
    }
    cout << endl;
    

    cout << "0/1 KNAPSACK (Dynamic Programming)\n\n";

    // Runs correctness tests, then benchmarks random weights and values with capacity scaled to input size
    testKnapsack("Test 1 - Basic case:", {1, 2, 3, 4, 5, 6, 7}, {3, 4, 5, 6, 7, 8, 9}, 12);
    testKnapsack("Test 2 - Standard case:", {1, 3, 4, 5}, {1, 4, 5, 7}, 7);
    testKnapsack("Test 3 - All items fit:", {1, 2, 3}, {10, 15, 40}, 6);
    testKnapsack("Test 4 - None fit:", {5, 6, 7}, {10, 20, 30}, 3);
    testKnapsack("Test 5 - Single item:", {4},{10}, 5);
    testKnapsack("Test 6 - Empty weights and values:", {}, {}, 10);

    cout << "Experimental Evaluation\n";
    cout << "Input Size\tTime (ms)\n";
    for (int n : {10, 50, 100, 200}) {
        vector<int> weights(n), values(n);

        for (int i = 0; i < n; i++) {
            weights[i] = rand() % 20 + 1;
            values[i] = rand() % 100 + 1;
        }

        int capacity = n * 5;

        double ms = timeIt([&]() {knapsack(weights, values, capacity); });
        cout << n << "\t\t" << ms << " ms\n";
    }
    cout << endl;

    return 0;
}
