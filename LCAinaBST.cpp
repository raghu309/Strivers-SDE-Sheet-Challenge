#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
TreeNode<int> *ans;

void getAns(TreeNode<int> *root, int p, int q) {
    if(!root)
        return;
    if(root->data >= p && root->data <= q) {
        ans = root;
        return;
    }
    if(root->data < p) {
        return getAns(root->right, p, q);
    }
    if(root->data > q) {
        return getAns(root->left, p, q);
    }
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    int p = P->data;
    int q = Q->data;
	ans = NULL;

    getAns(root, min(p, q), max(p, q));
    return ans;
}













