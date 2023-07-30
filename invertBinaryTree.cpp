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

bool getPath(TreeNode<int>* root, int leaf, vector<TreeNode<int>*>& st) {
    if (root == NULL)
        return false;

    if (root->data == leaf) {
        st.push_back(root);
        return true;
    }

    st.push_back(root);

    if ((root->left && getPath(root->left, leaf, st)) || (root->right && getPath(root->right, leaf, st))) {
        return true;
    }

    st.pop_back();
    return false;
}

TreeNode<int>* invertBinaryTree(TreeNode<int>* root, TreeNode<int>* leaf) {
    if (root == NULL) {
        return NULL;
    }

    vector<TreeNode<int>*> st;
    getPath(root, leaf->data, st);

    TreeNode<int>* newRoot = NULL;
    TreeNode<int>* parent = NULL;

    if (!st.empty()) {
        newRoot = parent = st.back();
        st.pop_back();
    }

    while (!st.empty()) {
        TreeNode<int>* cur = st.back();
        st.pop_back();

        if (cur->left == parent) {
            cur->left = NULL;
            parent->left = cur;
        } else {
            cur->right = cur->left;
            cur->left = NULL;
            parent->left = cur;
        }

        parent = parent->left;
    }

    return newRoot;
}
