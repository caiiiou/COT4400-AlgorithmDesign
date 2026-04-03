#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

// Solves 0/1 Knapsack using dynamic programming
// Returns the maximum value achievable within the given capacity
int knapsack(const std::vector<int>& weights, const std::vector<int>& values, int capacity);

#endif
