#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool flag;
int K;

void preOrder(TreeNode<int> *root, vector<int> &ans) {
	if(!root || !flag)
		return;
	if(flag)
		ans.push_back(root->data);
	if(root->data == K) {
		flag = false;
		return;
	}
	preOrder(root->left, ans);
	preOrder(root->right, ans);
	if(flag)
		ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	K = x;
	flag = true;
    vector<int> ans;
	preOrder(root, ans);
	return ans;
}



