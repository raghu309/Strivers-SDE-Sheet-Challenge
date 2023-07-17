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
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode* cur = root;
    
    while(cur) {
        if(cur->left) {
            TreeNode* t = cur->left;
            while(t->right && t->right!=cur)
                t = t->right;
            if(t->right == NULL) {
                t->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }else {
                t->right = NULL;
                cur = cur->right;
            }
        }else {
            ans.push_back(cur->data);
            cur = cur->right;
        }
    }
    return ans;
}