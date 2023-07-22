#include <bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* buildTree(vector<int> &po, vector<int> &io, int is, int ie,
                          int ps, int pe, unordered_map<int, int> &indexOf) {
     if(ps > pe) {
          return NULL;
     }
     int val = po[pe];
     TreeNode<int>* ans = new TreeNode<int>(val);
     int idx = indexOf[val];
     int leftSz = idx - is;
     int rightSz = ie - idx;

     ans->left = buildTree(po, io, is, idx-1, ps, ps+leftSz-1, indexOf);
     ans->right = buildTree(po, io, idx+1, ie, pe-rightSz, pe-1, indexOf);
     return ans;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	unordered_map<int, int> indexOf;
     for(int i=0; i<inOrder.size(); i++) {
          indexOf[inOrder[i]] = i;
     }
     return buildTree(postOrder, inOrder, 0, inOrder.size()-1, 0, inOrder.size()-1, indexOf);
}





