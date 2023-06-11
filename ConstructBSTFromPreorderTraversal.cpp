#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    if (preOrder.size() == 0)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);
    vector<int> left, right;
    for (int i = 1; i < preOrder.size(); i++)
    {
        if (preOrder[i] < root->data)
            left.push_back(preOrder[i]);
        else
            right.push_back(preOrder[i]);
    }

    root->left = preOrderTree(left);
    root->right = preOrderTree(right);
    return root;
}