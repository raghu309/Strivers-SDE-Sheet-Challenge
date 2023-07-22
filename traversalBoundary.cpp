#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void leftPrint(TreeNode<int>* root, vector<int> &ans) {
    if(!root)
        return;
    if(!root->left && !root->right)
        return;
    ans.push_back(root->data);
    if(root->left)
        leftPrint(root->left, ans);
    else
        leftPrint(root->right, ans);
}

void inOrder(TreeNode<int> *root, vector<int> &ans) {
    if(!root)
        return;
    inOrder(root->left, ans);
    if(!root->left && !root->right) {
        ans.push_back(root->data);
    }
    inOrder(root->right, ans);
}

void rightPrint(TreeNode<int> *root, vector<int> &ans) {
    if(!root)
        return;
    if(!root->left && !root->right)
        return;
    if(root->right) {
        rightPrint(root->right, ans);
    }else {
        rightPrint(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    if(!root) {
        return {};
    }
    vector<int> ans;
    ans.push_back(root->data);
    leftPrint(root->left, ans);
    inOrder(root->left, ans);
    inOrder(root->right, ans);
    rightPrint(root->right, ans);
    // ans.pop_back();
    return ans;
}