#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long ans = 0;

long long getAns(TreeNode<int> *root) {
    if(!root) {
        return 0;
    }
    long long left = getAns(root->left);
    long long right = getAns(root->right);

    if(root->left && root->right) {
        ans = max(ans, left+right+root->val);
    }
    return max(left, right)+root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
  if (!root || !root->left || !root->right) {
    return -1;
  }
  ans = 0;
  getAns(root);
  return ans;
}



