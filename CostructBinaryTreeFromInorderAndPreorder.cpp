#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
unordered_map<int, int> m;

TreeNode<int> *recur(int low, int high, vector<int> &preorder, int &itr)
{
    if (low > high)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[itr++]);
    int mid = m[root->data];
    root->left = recur(low, mid - 1, preorder, itr);
    root->right = recur(mid + 1, high, preorder, itr);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    m.clear();
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;

    int itr = 0;
    return recur(0, inorder.size() - 1, preorder, itr);
}