#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int recur(BinaryTreeNode<int> *root, bool &res)
{
    if (root == NULL || res == false)
        return 0;

    int left = recur(root->left, res);
    int right = recur(root->right, res);

    if (abs(left - right) > 1)
        res = false;

    return max(left, right) + 1;
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    bool res = true;

    recur(root, res);
    return res;
}