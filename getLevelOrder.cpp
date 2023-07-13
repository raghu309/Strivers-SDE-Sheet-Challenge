#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root)
        return {};
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(q.size()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            auto ptr = q.front();
            q.pop();
            ans.push_back(ptr->val);
            if(ptr->left)
                q.push(ptr->left);
            if(ptr->right)
                q.push(ptr->right);
        }
    }
    return ans;
}















