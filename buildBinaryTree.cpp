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
TreeNode<int>* buildTree(vector<int> &preOrder, vector<int> &inOrder, int ps,
 int pe, int is, int ie, unordered_map<int, int> &indexOf) {
    if(ps > pe) {
        return NULL;
    }
    int val = preOrder[ps];
    TreeNode<int> *ans = new TreeNode<int>(val);
    int idx = indexOf[val];
    int leftSz = idx - is;
    int rightSz = ie - idx;
    ans->left = buildTree(preOrder, inOrder, ps+1, ps+leftSz, is, idx-1, indexOf);
    ans->right = buildTree(preOrder, inOrder, ps+leftSz+1, pe, idx+1, ie, indexOf);

    return ans;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int, int> indexOf;
    for(int i=0; i<inorder.size(); i++) {
        indexOf[inorder[i]] = i;
    }
    return buildTree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1, indexOf);
}






