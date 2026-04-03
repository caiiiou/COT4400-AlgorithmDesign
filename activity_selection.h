#ifndef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

#include <vector>
#include <utility>

// Selects the maximum number of non-overlapping activities
// Input: list of (start, finish) pairs
// Returns: indices of selected activities
std::vector<int> activitySelection(std::vector<std::pair<int,int>>& activities);

#endif
