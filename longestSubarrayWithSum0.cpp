#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    int res = 0, sum = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            res = i + 1;
        else if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }

    return res;
}