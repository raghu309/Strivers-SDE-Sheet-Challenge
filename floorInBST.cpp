#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    if(!root)
        return -1e9;
    if(root->val > X) {
        return floorInBST(root->left, X);
    }
    if(root->val == X) {
        return root->val;
    }
    return max(root->val, floorInBST(root->right, X));
}




