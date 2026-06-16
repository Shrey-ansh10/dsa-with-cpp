// LC-105 : Construct Binary Tree from Preorder and Inorder Traversal

#include<iostream>
#include<vector>
using namespace std;

#include "../tree_node.h"

// search root in the "inorder" array
    int search(vector<int>& inorder, int root, int left, int right){
    for(int i = left; i<=right; i++){
        if(inorder[i] == root) return i;
    }
    return -1;
}

TreeNode* buildActualTree(vector<int>& preorder, vector<int>& inorder, int& preOrderIdx, int left, int right) {
    // base condition for leaf nodes
    if(right<left) return nullptr;

    TreeNode* root = new TreeNode(preorder[preOrderIdx]);

    // search root in the "inorder" array, to determine left and right sub tree
    int inOrderIdx = search(inorder, preorder[preOrderIdx], left, right);

    preOrderIdx++;

    // recursive calls to build left and right sub-trees
    // NOTE : here we calll right root first to build right subtree first, cos we're traversing reverse on postorder array, and in postorder we build root->right->left | which is obtained by reversing the postorder: left->right->root 
    root->left = buildActualTree(preorder, inorder, preOrderIdx, left, inOrderIdx-1);
    root->right = buildActualTree(preorder, inorder, preOrderIdx, inOrderIdx+1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIdx = 0; // this wil track the idx in preorder to determine root

    return buildActualTree(preorder, inorder, preOrderIdx, 0, inorder.size()-1);
}