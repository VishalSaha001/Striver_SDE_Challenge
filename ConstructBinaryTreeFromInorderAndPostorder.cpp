/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
#include <bits/stdc++.h>
unordered_map<int, int> m;

TreeNode<int> *recur(int low, int high, vector<int> &postOrder, int &itr)
{
    if (low > high)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postOrder[itr--]);
    int mid = m[root->data];
    root->right = recur(mid + 1, high, postOrder, itr);
    root->left = recur(low, mid - 1, postOrder, itr);
    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    m.clear();
    for (int i = 0; i < inOrder.size(); i++)
        m[inOrder[i]] = i;

    int itr = postOrder.size() - 1;
    return recur(0, postOrder.size() - 1, postOrder, itr);
}
