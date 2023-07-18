#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

void preOrder(TreeNode<int> *root, map<int, pair<int, int>> &mpp, int x, int depth) {
    if(!root)
        return;
    if(mpp.count(x)) {
        if(mpp[x].first >= depth) {
            mpp[x] = {depth, root->val};
        }
    }else {
        mpp[x] = {depth, root->val};
    }
    preOrder(root->left, mpp, x-1, depth+1);
    preOrder(root->right, mpp, x+1, depth+1);
}

vector<int> getTopView(TreeNode<int> *root) {
    map<int, pair<int, int>> mpp;
    preOrder(root, mpp, 0, 0);
    vector<int> ans;
    for(auto pr:mpp) {
        ans.push_back(pr.second.second);
    }
    return ans;
}












