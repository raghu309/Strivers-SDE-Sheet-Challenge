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

class BSTiterator
{
stack<TreeNode<int>*> st;
public:
    BSTiterator(TreeNode<int> *root)
    {
        addToStack(root);
    }

    void addToStack(TreeNode<int> *root) {
        if(!root)
            return;
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int> *rv = st.top();
        st.pop();
        addToStack(rv->right);
        return rv->data;
    }

    bool hasNext()
    {
        return st.size();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/