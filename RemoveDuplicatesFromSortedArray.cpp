int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[cnt - 1])
            arr[cnt++] = arr[i];
    }
    return cnt;
}