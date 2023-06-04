#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    int res = 0;
    // vector<int> dp(n,INT_MAX);
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(dp, dp + res, arr[i]) - dp;
        dp[idx] = arr[i];
        if (idx == res)
            res++;
    }
    return res;
}
