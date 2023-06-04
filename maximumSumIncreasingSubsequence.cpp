#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    int res = rack[0];
    int dp[n];
    memset(dp, 0, sizeof(dp));

    dp[0] = rack[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = rack[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (rack[i] > rack[j])
                dp[i] = max(dp[i], dp[j] + rack[i]);
        }
        res = max(res, dp[i]);
    }
    return res;
}