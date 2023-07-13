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
void pre(TreeNode<int> *root, int depth, vector<int> &ans) {
    if(!root)
        return;
    if(depth == ans.size()) {
        ans.push_back(root->data);
    }
    pre(root->left, depth+1, ans);
    pre(root->right, depth+1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    pre(root, 0, ans);
    return ans;
}