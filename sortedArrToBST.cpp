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
TreeNode<int>* buildTree(vector<int> &arr, int l, int r) {
    if(l > r)
        return NULL;
    int mid = (l+r)/2;
    int val = arr[mid];
    TreeNode<int> *ans = new TreeNode<int>(val);
    ans->left = buildTree(arr, l, mid-1);
    ans->right = buildTree(arr, mid+1, r);
    return ans;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return buildTree(arr, 0, n-1);
}














