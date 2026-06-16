// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
// Given two binary trees original and cloned and given a reference to a node target in the original tree.
// The cloned tree is a copy of the original tree.
// Return a reference to the same node in the cloned tree.
// Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// The values of the nodes of the tree are unique.
// target node is a node from the original tree and is not null.
 
// Follow up: Could you solve the problem if repeated values on the tree are allowed?

#include<iostream>
using namespace std;

#include "../tree_node.h"

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // the target is a reference to node in the opriginal tree
        // Therefore we need to find the node in the original and then return the correponding node from the cloned tree
        
        // if original becomes nullptr at any point
        // if(original == nullptr) return nullptr; // return null

        // if(original == target) return cloned;

        // // Approach-1
        // TreeNode* leftSearch = getTargetCopy(original->left, cloned->left, target); // Search in left subtree
        // TreeNode* rightSearch = getTargetCopy(original->right, cloned->right, target); // // Search in right subtree

        // return leftSearch != nullptr ? leftSearch : rightSearch;

        
        
        // Approach-2
        // // Search in left subtree
        // TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        // if (leftResult != nullptr) return leftResult;
    
        // // Search in right subtree
        // return getTargetCopy(original->right, cloned->right, target);

        
        
        
        // Approach-3 BFS
        queue<TreeNode*> q;
        q.push(original);
        q.push(cloned);

        while(!q.empty()){
            TreeNode* currOrig = q.front();
            q.pop();
            TreeNode* currClon = q.front();
            q.pop();

            if(currOrig == target) return currClon;
            
            if(currOrig->left != nullptr){
                q.push(currOrig->left);
                q.push(currClon->left);
            } 
            if(currOrig->right != nullptr){
                q.push(currOrig->right);
                q.push(currClon->right);
            } 
        }

        return nullptr;
    }