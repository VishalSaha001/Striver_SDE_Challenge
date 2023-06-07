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
unordered_map<int, int> m;

TreeNode<int> *recur(int low, int high, vector<int> &preOrder, int &itr)
{
    if (low > high)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preOrder[itr++]);
    int mid = m[root->data];
    root->left = recur(low, mid - 1, preOrder, itr);
    root->right = recur(mid + 1, high, preOrder, itr);
    return root;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    vector<int> inOrder(preOrder);
    sort(inOrder.begin(), inOrder.end());
    int itr = 0;
    // m.clear();
    for (int i = 0; i < inOrder.size(); i++)
        m[inOrder[i]] = i;

    // int low=0,high=preOrder.size()-1;

    // while(low<=high)
    // {
    //     TreeNode<int>* root=preOrder[itr++];
    //     int mid=m[root->data];

    // }

    return recur(0, preOrder.size() - 1, preOrder, itr);
}