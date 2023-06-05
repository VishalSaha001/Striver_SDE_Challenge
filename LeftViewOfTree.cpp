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
unordered_set<int> s;

void recur(TreeNode<int> *root, int height, vector<int> &res)
{
    if (root == NULL)
        return;

    if (s.find(height) == s.end())
    {
        s.insert(height);
        res.push_back(root->data);
    }

    recur(root->left, height + 1, res);
    recur(root->right, height + 1, res);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    s = unordered_set<int>();
    vector<int> res;
    recur(root, 0, res);
    return res;
}

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
// unordered_set<int> s;

void recur(TreeNode<int>* root,int &mx, int height,vector<int>& res)
{
    if(root==NULL)
        return;
    
    if(height>mx)
    {
        mx=height;
        res.push_back(root->data);
    }

    recur(root->left,mx,height+1,res);
    recur(root->right,mx,height+1,res);

}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> res;
    int mx=-1;
    recur(root,mx,0,res);
    return res;

}