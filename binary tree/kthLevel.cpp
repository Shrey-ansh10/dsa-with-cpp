// print all nodes at Kth level of a Binary Tree

#include<iostream>
using namespace std;

#include "../tree_node.h"


void kthLevel(TreeNode* root, int k){

    if(root == nullptr) return; // edge case - where one child, either left or right is null

    if(k==1){ // when we reach k==1, it's the desired level for which we need to print all nodes
        cout << root->val;
        return;
    }

    kthLevel(root->left, k-1); // keep decreasing k by 1
    kthLevel(root->right, k-1);
}