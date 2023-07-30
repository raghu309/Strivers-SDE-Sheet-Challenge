#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> *prev;

TreeNode<int>* flatten(TreeNode<int> *root) {
    if(!root)
        return NULL;
    auto lt = flatten(root->left);
    auto rt = flatten(root->right);

    if(lt) {
        lt->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    auto ret = root;
    if(rt) {
        ret = rt;
    }else if(lt) {
        ret = lt;
    }
    return ret;
}


TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    flatten(root);
    return root;
}