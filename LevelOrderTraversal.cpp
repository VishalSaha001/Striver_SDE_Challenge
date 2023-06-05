#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> res;
    queue<BinaryTreeNode<int> *> q;

    if (root)
        q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        res.push_back(root->val);
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
    return res;
}