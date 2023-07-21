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

int getMaxWidth(TreeNode<int> *root)
{
    if(!root)
        return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ans = 0;
    while(q.size()) {
        int sz = q.size();
        ans = max(ans, (int)q.size());
        // long long offset = -1;
        for(int i=0; i<sz; i++) {
            auto t = q.front();
            q.pop();
            if(t->left) {
                q.push(t->left);
            }
            if(t->right) {
                q.push(t->right);
            }
        }
    }
    return ans;
}









