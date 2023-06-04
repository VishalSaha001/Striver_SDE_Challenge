#include <bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    int dp[w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            if (weights[i - 1] <= j)
                dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
        }
    }

    return dp[w];
}