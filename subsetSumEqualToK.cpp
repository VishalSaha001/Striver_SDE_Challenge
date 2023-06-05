#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    bool dp[k + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        dp[0] = true;
        for (int j = k; j >= 1; j--)
        {
            if (arr[i - 1] <= j)
                dp[j] = dp[j] || dp[j - arr[i - 1]];
        }
    }
    return dp[k];
}