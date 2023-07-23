#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
int K;
bool f = false;
unordered_set<int> stt;

void inOrder(BinaryTreeNode<int> *root) {
    if(!root)
        return;
    inOrder(root->left);
    if(stt.count(K-root->data))
        f = true;
    stt.insert(root->data);
    inOrder(root->right);
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stt.clear();
    f = false;
    K = k;
    inOrder(root);
    return f;
}








