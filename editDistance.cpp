#include <bits/stdc++.h>
int editDistance(string str1, string str2)
{
    // write you code here
    int m = str1.size(), n = str2.size();

    vector<int> dp1(n + 1), dp2(n + 1);

    for (int i = 0; i <= n; i++)
        dp1[i] = i;

    for (int i = 1; i <= m; i++)
    {
        dp2[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp2[j] = dp1[j - 1];
            else
                dp2[j] = min({dp1[j - 1], dp1[j], dp2[j - 1]}) + 1;
        }
        dp1 = dp2;
    }

    return dp2[n];
}