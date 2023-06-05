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

class BSTiterator
{
private:
    stack<TreeNode<int> *> s;
    TreeNode<int> *root;

public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        this->root = root;
    }

    int next()
    {
        // write your code here
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            int res = root->data;
            root = root->right;
            return res;
        }
        return -1;
    }

    bool hasNext()
    {
        return root || !s.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/