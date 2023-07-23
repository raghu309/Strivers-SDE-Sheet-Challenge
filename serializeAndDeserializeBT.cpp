#include <bits/stdc++.h>

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
    if(!root)
        return "";
    queue<TreeNode<int>*> q;
    q.push(root);
    string ans = "";
    while(q.size()) {
        auto cur = q.front();
        q.pop();
        if(cur == NULL) {
            ans += "#";
            ans += ",";
            continue;
        }
        ans += to_string(cur->data);
        ans += ",";
        q.push(cur->left);
        q.push(cur->right);
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &data)
{
    if(data == "")
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()) {
        TreeNode<int> *cur = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#") {
            cur->left = NULL;
        }else {
            cur->left = new TreeNode<int>(stoi(str));
            q.push(cur->left);
        }

        getline(s, str, ',');
        if(str == "#") {
            cur->right = NULL;
        }else {
            cur->right = new TreeNode<int>(stoi(str));
            q.push(cur->right);
        }
    }
    return root;
}



