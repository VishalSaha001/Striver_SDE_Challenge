#include <bits/stdc++.h>
int lcs(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<int> dp(n + 1), dp2(n + 1);

    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp2[j] = dp[j - 1] + 1;
            else
                dp2[j] = max(dp[j], dp2[j - 1]);
        }
        dp = dp2;
    }
    return dp2[n];
}