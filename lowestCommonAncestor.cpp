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
int ans;

bool lca(TreeNode<int> *root, int x, int y) {
    if(!root)
        return false;
    bool left = lca(root->left, x, y);
    bool right = lca(root->right, x, y);
    if(left && right && ans == -1e9)
        ans = root->data;
    if(root->data == x || root->data == y) {
        if(left || right) {
            ans = root->data;
        }
        return true;
    }
    return left | right;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	ans = -1e9;
    lca(root, x, y);
    return ans;
}