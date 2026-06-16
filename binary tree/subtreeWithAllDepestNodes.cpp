// LC-865 : Smallest Subtree with all the Deepest Nodes
// Given the root of a binary tree, the depth of each node is the shortest distance to the root.
// Return the smallest subtree such that it contains all the deepest nodes in the original tree.

// Same Question with different Question Statement
// LC-1123: Lowest Common Ancestor of Deepest Leaves 
// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
// Recall that:
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

#include<iostream>
using namespace std;

#include "../tree_node.h"


// Solution Approach: Inspired from lowest common ancestor approach
// Do Post order Traversal -- keep tracking depth as you go down
// Each node returns {depth, root of subtree containing all depest nodes}
// At each Node we have following options:
// -> Left subtree has deeper nodes => return left's ans
// -> right subtree has deeper nodes => return right's ans
// -> Both subtrees have same level of depth => return depth and this root | i.e. {left.first, root}


// Helper Function - TC : O(n)
pair<int, TreeNode*> findAns(TreeNode* root, int depth) {
        
        if(root == nullptr) return {depth-1, nullptr};

        pair<int, TreeNode*> left = findAns(root->left, depth+1);
        pair<int, TreeNode*> right = findAns(root->right, depth+1);

        if(left.first > right.first) return left;
        else if(left.first < right.first) return right;
        else return {left.first, root};
}


// Main function
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    
    pair<int, TreeNode*> p = findAns(root, 0);
    return p.second;
}