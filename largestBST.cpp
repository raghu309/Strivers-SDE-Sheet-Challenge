#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
int ans;

vector<int> dfs(TreeNode<int>* root) {
    if(!root) {
        return {INT_MAX, INT_MIN, 0};
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    if(left[1]<root->data && root->data<right[0]) {
        ans = max(ans, 1+left[2]+right[2]);
        return {min(left[0], root->data), max(root->data, right[1]), left[2]+right[2]+1};
    }
    return {INT_MIN, INT_MAX, 0};
}


int largestBST(TreeNode<int>* root) 
{
    ans = 0;
    dfs(root);
    return ans;
}
