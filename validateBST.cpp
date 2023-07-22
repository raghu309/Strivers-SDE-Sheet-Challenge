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

bool validate(BinaryTreeNode<int> *root, int mini, int maxi) {
    if(!root)
        return true;
    if(root->data < mini || root->data > maxi)
        return false;
    return validate(root->left, mini, root->data) && 
            validate(root->right, root->data, maxi);
}

bool validateBST(BinaryTreeNode<int> *root) {
    return validate(root, INT_MIN, INT_MAX);
}