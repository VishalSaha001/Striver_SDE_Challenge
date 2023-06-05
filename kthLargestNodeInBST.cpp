#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    stack<TreeNode<int> *> s;
    int itr = 1;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->right;
        }
        root = s.top();
        s.pop();
        if (itr == k)
            return root->data;
        itr++;
        root = root->left;
    }
    return -1;
}
