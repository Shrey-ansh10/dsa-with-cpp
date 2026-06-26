// Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

#include<iostream>
#include<vector>
using namespace std;

#include "../tree_node.h"
#include "sortedArrayToBST.h"

TreeNode* sortedArrayToBSTSol::buildTree(vector<int>& nums, int st, int end){
    if(st>end) return nullptr;

    int mid = st + (end-st) / 2;

    TreeNode* root = new TreeNode(nums[mid]); // create the root
    root->left = buildTree(nums, st, mid-1); // build left
    root->right = buildTree(nums, mid+1, end); // build right

    return root;
}

// this is the main function given - but we will need to write a helper function to solve this problem.
TreeNode* sortedArrayToBSTSol::sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size()-1);
}    