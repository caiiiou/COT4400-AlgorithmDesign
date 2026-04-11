/*
* ACTIVITY SELECTION PROBLEM
* SOLVED USING GREEDY ALGORITHM
* TIME: O(nlogn)
* SPACE: O(n)
* Overall idea is that whenever more than one activity overlaps, we should pick the one that finishes first 
* so we can then pick more activities without running into conflict at activity times 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> taskSt, pair<int, int> taskFin)
{
    // how we sort by the finish times
    return taskSt.second < taskFin.second;
}

void activitySelection(vector<int>& start, vector<int>& finish)
{
    vector<pair<int, int>> taskArr;

    // combine the start and finish times into pairs
    for(int i = 0; i < start.size(); i++)
    {
        taskArr.push_back({start[i], finish[i]});
    }

    sort(taskArr.begin(), taskArr.end(), compare);
    
    // If taskArr is empty
    if(taskArr.size() == 0)
    {
        cout << "No activities are available.\n";
        return;
    }

    vector<pair<int, int>> selectedAct;

    selectedAct.push_back(taskArr[0]);
    int j = 0;

    for(int i = 1; i < taskArr.size(); i++)
    {
        if(taskArr[i].first >= taskArr[j].second)
        {
            selectedAct.push_back(taskArr[i]);
            j = i;
        }
    }

    // OUTPUT FOR SELECTED ACTIVITIES
    cout << "Your selected activities:\n";
    int count = 1;
    for(auto activity : selectedAct)
    {
        cout << "Activity: " << count << " Start = " << activity.first << ", Finish = " << activity.second << endl;
        count++;
    }
    
    // OUTPUT THE TOTAL COUNT
    cout << "Total Count of Activities Selected: " << selectedAct.size() << endl;
    
}
    
