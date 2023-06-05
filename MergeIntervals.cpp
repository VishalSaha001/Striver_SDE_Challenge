#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > end)
        {
            res.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else
            end = max(end, intervals[i][1]);
    }
    res.push_back({start, end});

    return res;
}
