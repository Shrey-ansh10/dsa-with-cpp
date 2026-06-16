// LC-530 and 783 : Find the min differnce btw two BST nodes.

#include<iostream>
using namespace std;

#include "../tree_node.h"


// As we know that if we have a valid BST, we can do a inorder travelral on it and get the values in a sorted order.
// If we take the difference between each consecutive node, we will have a list of all differences, and from that we have obtain the min difference. 
// So here we will do the same: 
//  - First we will traverse the left subtree.
//  - Then we will come to root, check if it has a previous(adjacent) node and calculate the abs difference between previous and current node.
//  - Then we will proceed to right subtree. 
// Finally we will return the finalMinDiff we have obtained which is the min diff, from all the differences of the consecutive/adjacent nodes.
// Note we will create a global pointer called prev, which will point to the last visited node in the tree.
// Also we will create a finalMinDiff variable will will be initilized with INT_MAX and will store the min difference amongst all nodes of BST.
// (Applologies for lasy explaination.)

class Solution {
public:

    TreeNode* prev = nullptr;
    int finalMinDiff = INT_MAX;
    
    int minDiffInBST(TreeNode* root) {
        // base case
        if(root == nullptr) return finalMinDiff;

        // traverse left subtree if it exist
        if(root->left){
            int diff = minDiffInBST(root->left);
            finalMinDiff = min(finalMinDiff, diff);
        }

        // for root check if prev value exist and calculate difference
        if(prev){
            finalMinDiff = min(abs(prev->val - root->val), finalMinDiff); // make sure to calculate absolute difference between current and prev node.
        }

        prev = root; // assign last visited node to prev pointer

        // traverse right subtree if it exist
        if(root->right){
            int diff = minDiffInBST(root->right);
            finalMinDiff = min(finalMinDiff, diff);
        }

        return finalMinDiff;
    }
};  