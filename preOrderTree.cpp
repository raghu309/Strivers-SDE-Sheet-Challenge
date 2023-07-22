#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

int lt(vector<int> &v, int lo, int hi, int b) {
    while(hi - lo > 1) {
        int mid = (hi+lo)/2;
        if(v[mid] < b) {
            lo = mid;
        }else {
            hi = mid;
        }
    }
    if(v[hi] < b) {
        return hi;
    }else if(v[lo] < b) {
        return lo;
    }
    return -1;
}

TreeNode<int>* buildTree(vector<int> &preOrder, int s, int e) {
    if(s > e)
        return NULL;
    int val = preOrder[s];
    TreeNode<int>* ans = new TreeNode<int>(val);
    if(s == e) return ans;
    int m = lt(preOrder, s+1, e, val);
    if(m != -1) {
        ans->left = buildTree(preOrder, s+1, m);
    }
    if(m == -1) {
        ans->right = buildTree(preOrder, s+1, e);
    }else {
        ans->right = buildTree(preOrder, m+1, e);
    }
    return ans;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    return buildTree(preOrder, 0, preOrder.size()-1);
}




