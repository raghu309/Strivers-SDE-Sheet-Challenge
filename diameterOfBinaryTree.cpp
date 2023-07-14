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

int ans = 0;

int getAns(TreeNode<int> *root) {
    if(!root)
        return 0;
    int left = getAns(root->left);
    int right = getAns(root->right);
    if(left!=0 && right!=0)
        ans = max(ans, left+right);
    return 1+max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    ans = 0;
	int val = getAns(root);
    ans = max(ans, val-1);
    return ans;
}






