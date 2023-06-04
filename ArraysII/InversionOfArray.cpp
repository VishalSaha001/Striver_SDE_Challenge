#include <bits/stdc++.h> 


int merge(int low, int mid, int high, long long *arr)
{
    int inv=0;
    vector<int> left(mid-low+1),right(high-mid);

    for(int i=low;i<=mid;i++)
        left[i-low]=arr[i];
    
    for(int i=mid+1;i<=high;i++)
        right[i-mid-1]=arr[i];
    
    int i=0,j=0,k=low;

    while(i<left.size() && j<right.size())
    {
        if(right[j]<left[i])
        {
            inv+=(mid-low+1-i);
            arr[k++]=right[j++];
        }
        else
            arr[k++]=left[i++];
    }

    while(i<left.size())
        arr[k++]=left[i++];

    while(j<right.size())
        arr[k++]=right[j++];

    return inv;
}

int mergeSort(int low,int high,long long *arr)
{
    if(low>=high)
        return 0;
    
    int mid=low+(high-low)/2;
    return mergeSort(low,mid,arr)+mergeSort(mid+1,high,arr)+
    merge(low,mid,high,arr);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(0,n-1,arr);
}