#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    long res = 1;
    long mult = x;
    while (n)
    {
        if (n & 1)
        {
            res *= mult;
            res %= m;
        }
        mult *= mult;
        mult %= m;

        n >>= 1;
    }

    return res;
}