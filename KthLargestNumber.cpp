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
int ans;
int K;
void inOrder(TreeNode<int> *root) {
    if(!root)
        return;
    inOrder(root->right);
    K--;
    if(K == 0)
        ans = root->data;
    inOrder(root->left);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    ans = -1;
    K = k;
    inOrder(root);
    return ans;
}
