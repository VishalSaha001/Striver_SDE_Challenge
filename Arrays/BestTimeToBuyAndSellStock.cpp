#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int res=0;
    int mn=INT_MAX;

    for(int price:prices)
    {
        mn=min(mn,price);
        res=max(res,price-mn);
    }

    return res;
}