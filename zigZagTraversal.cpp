#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root)
        return {};
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int level = 1;
    while(q.size()) {
        int sz = q.size();
        vector<int> t;
        for(int i=0; i<sz; i++) {
            auto cur = q.front();
            q.pop();
            t.push_back(cur->data);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        if(level % 2 == 0) {
            reverse(t.begin(), t.end());
        }
        for(auto el:t)
            ans.push_back(el);
        level++;
    }
    return ans;
}







