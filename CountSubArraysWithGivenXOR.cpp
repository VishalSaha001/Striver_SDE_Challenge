#include <bits/stdc++.h>

#include <vector>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int res = 0, sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        sum ^= arr[i];
        if (sum == x)
            res++;

        if (m.find(sum ^ x) != m.end())
            res += m[sum ^ x];

        m[sum]++;
    }
    return res;
}