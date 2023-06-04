#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    int res = 0;
    unordered_map<char, int> m;

    for (int i = 0, j = 0; j < input.size(); j++)
    {
        m[input[j]]++;

        while (m.size() != j - i + 1)
        {
            m[input[i]]--;
            if (m[input[i]] == 0)
                m.erase(input[i]);
            i++;
        }
        res = max(res, j - i + 1);
    }

    return res;
}