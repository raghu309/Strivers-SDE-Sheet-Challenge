#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

void inOrder(BinaryTreeNode<int> *root, int x, int curDepth, map<int, pair<int, int>> &mpp) {
    if(!root)
        return;
    if(mpp.count(x)) {
        int prevDepth = mpp[x].first;
        if(curDepth >= prevDepth) {
            mpp[x] = {curDepth, root->data};
        }
    }else {
        mpp[x] = {curDepth, root->data};
    }
    inOrder(root->left, x-1, curDepth+1, mpp);
    inOrder(root->right, x+1, curDepth+1, mpp);
}

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int, pair<int, int>> mpp;
    inOrder(root, 0, 0, mpp);
    vector<int> ans;
    for(auto pr:mpp) {
        ans.push_back(pr.second.second);
    }
    return ans;
}
