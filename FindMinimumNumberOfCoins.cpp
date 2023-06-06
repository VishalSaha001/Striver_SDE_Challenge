#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int res = 0;
    int i = 0;

    int coin[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    while (amount)
    {
        res += amount / coin[i];
        amount = amount % coin[i];
        i++;
    }
    return res;
}
