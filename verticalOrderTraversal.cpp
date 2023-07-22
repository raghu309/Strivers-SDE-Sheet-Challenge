#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int>*, int>> q;
    map<int, vector<int>> mpp;

    q.push({root, 0});
    while(q.size()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            auto node = q.front().first;
            int x = q.front().second;
            q.pop();

            mpp[x].push_back(node->data);
            if(node->left) {
                q.push({node->left, x-1});
            }
            if(node->right) {
                q.push({node->right, x+1});
            }
        }
    }

    vector<int> ans;
    for(auto &pr:mpp) {
        for(auto &el:pr.second) {
            ans.push_back(el);
        }
    }
    return ans;
}






