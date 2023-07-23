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
int ans;
int K;
void inOrder(TreeNode<int> *root) {
    if(!root)
        return;
    inOrder(root->left);
    K--;
    if(K == 0)
        ans = root->data;
    inOrder(root->right);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	ans = -1;
    K = k;
    inOrder(root);
    return ans;
}









