/*
* 0/1 KNAPSACK PROBLEM
* SOLVED USING DYNAMIC PROGRAMMING
* TIME: O(n * w)
* SPACE: O(n * w) 
* Where n is the amount of objects and w is the capacity of the knapsack.
* The idea of the memoization approach is to search check if we have checked the object previously. If it has not
* been accessed previously, then we store it in a 2D array which is later accessed to avoid repeated recursion.
*/

#include <vector>
#include <algorithm>
using namespace std;

// TODO: 0/1 knapsack using DP
int knapsackRecurr(vector<int>& weights, vector<int>& values, int capacity, int currItem, vector<vector<int>>& memo){
    int result = 0;

    if (currItem == weights.size() || capacity == 0){ //checks if currItem checked each item or capacity is 0
        return 0;
    }

    if (memo[currItem][capacity] != -1){ //checks if memo has been occupied by the current item and capacity combo
        return memo[currItem][capacity];
    }

    else if (weights[currItem] > capacity){  //if current item doesnt fit in capacity, go to next item
        memo[currItem][capacity] = knapsackRecurr(weights, values, capacity, currItem + 1, memo);
    }
    else{ //else check if we take the next item or not recursively
        memo[currItem][capacity]  = max(values[currItem] + knapsackRecurr(weights, values, capacity - weights[currItem], currItem + 1, memo),
                                    knapsackRecurr(weights, values, capacity, currItem + 1, memo)); 
    }
    
    result = memo[currItem][capacity];

    return result;
}

int knapsack(vector<int>& weights, vector<int>& values, int capacity){
    
    int currItem = 0;
    vector<vector<int>> memo(weights.size(), vector<int>(capacity + 1, -1));//initializes memo and sets every slot to -1 so we know it is empty

    return knapsackRecurr(weights, values, capacity, currItem, memo);
}