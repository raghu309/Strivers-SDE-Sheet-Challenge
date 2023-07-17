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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode* cur = root;

    while(cur) {
        if(cur->right) {
            TreeNode* t = cur->right;
            while(t->left && t->left != cur)
                t = t->left;
            if(t->left == NULL) {
                t->left = cur;
                ans.push_back(cur->data);
                cur = cur->right;
            }else {
                t->left = NULL;
                cur = cur->left;
            }
        }else {
            ans.push_back(cur->data);
            cur = cur->left;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}




