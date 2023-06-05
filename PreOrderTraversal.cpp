#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> res;
    stack<TreeNode *> s;

    while (root || !s.empty())
    {
        while (root)
        {
            res.push_back(root->data);
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        root = root->right;
    }

    return res;
}