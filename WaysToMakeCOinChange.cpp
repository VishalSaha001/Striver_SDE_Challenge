#include <bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    long dp[value + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[0] = 1;
        for (int j = 1; j <= value; j++)
        {
            if (denominations[i - 1] <= j)
                dp[j] = dp[j] + dp[j - denominations[i - 1]];
        }
    }
    return dp[value];
}