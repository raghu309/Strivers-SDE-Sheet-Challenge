#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    TreeNode* cur = root;
    vector<int> ans;
    while(cur) {
        if(cur->left) {
            TreeNode* t = cur->left;
            while(t->right && t->right != cur)
                t = t->right;
            if(t->right == NULL) {
                t->right = cur;
                cur = cur->left;
            }else {
                t->right = NULL;
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }else {
            ans.push_back(cur->data);
            cur = cur->right;
        }
    }
    return ans;
}