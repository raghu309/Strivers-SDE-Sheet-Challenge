#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int getAns(BinaryTreeNode<int> *root, int x) {
    if(!root)
        return 2e9;
    int ans = root->data>=x?root->data:2e9;
    if(root->data < x) {
        return getAns(root->right, x);
    }else {
        return min(ans, getAns(root->left, x));
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = getAns(node, x);
    return ans>1e9?-1:ans;
}



