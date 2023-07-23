#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int pre, suc;
int prevv;
int K;

void inOrder(BinaryTreeNode<int> *root) {
    if(!root) return;
    inOrder(root->left);
    if(root->data == K) {
        pre = prevv;
    }
    if(prevv == K) {
        suc = root->data;
    }
    prevv = root->data;

    inOrder(root->right);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pre = -1;
    suc = -1;
    prevv = -1;
    K = key;
    inOrder(root);
    return {pre, suc};
}




