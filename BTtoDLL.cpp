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

BinaryTreeNode<int>* head;
BinaryTreeNode<int>* pre;

void dfs(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    dfs(root->left);
    if(!head) {
        head = root;
        pre = root;
    }else {
        pre->right = root;
        root->left = pre;
        pre = root;
    }
    dfs(root->right);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    head = NULL;
    dfs(root);
    return head;
}