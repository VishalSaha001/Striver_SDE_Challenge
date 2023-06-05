#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *recur(int low, int high, vector<int> &arr)
{
    if (low > high)
        return NULL;

    int mid = low + (high - low) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = recur(low, mid - 1, arr);
    root->right = recur(mid + 1, high, arr);
    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return recur(0, n - 1, arr);
}