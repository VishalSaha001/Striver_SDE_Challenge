#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();
    stack<int> s, sIndex;

    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() <= price[i])
        {
            sIndex.pop();
            s.pop();
        }

        if (s.empty())
            res[i] = i + 1;
        else
            res[i] = i - sIndex.top();
        s.push(price[i]);
        sIndex.push(i);
    }
    return res;
}