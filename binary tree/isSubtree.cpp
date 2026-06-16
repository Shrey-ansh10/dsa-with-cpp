// LC 572 : Subtree of another tree.
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


#include <iostream>
#include "../tree_node.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q){

    if(p == nullptr ||  q == nullptr) return p==q;

    bool leftSubTree = isSameTree(p->left, q->left);
    bool rightSubTree = isSameTree(p->right, q->right);

    return leftSubTree && rightSubTree && p->val == q->val;
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) { // this function will find the subRoot in the main tree
    
    if(root== nullptr || subRoot == nullptr) return root==subRoot;

    // If we find subroot in the main tree - following will check if that subtree is same as subRoot's tree
    if(root->val == subRoot->val && isSameTree(root, subRoot)){ // when a node is found with same value as subRoot, check if the subtree from that node is same with the tree from subRoot
        return true; // this function will help in that
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
