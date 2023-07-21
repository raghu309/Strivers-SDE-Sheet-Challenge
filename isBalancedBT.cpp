#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool ans;

int dfs(BinaryTreeNode<int> *root) {
    if(!root)
        return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if(abs(right-left) > 1) {
        ans = false;
    }
    return max(left, right)+1;
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    ans = true;
    dfs(root);
    return ans;
}




