#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	vector<int> res(n+m);
	int i=0,j=0,k=0;

	while(i<m && j<n)
	{
		if(arr1[i]<arr2[j])
			res[k++]=arr1[i++];
		else
			res[k++]=arr2[j++];
	}

	while(i<m)
		res[k++]=arr1[i++];
	
	while(j<n)
		res[k++]=arr2[j++];
	
	return res;
}