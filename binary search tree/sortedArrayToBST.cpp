// Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& nums, int st, int end){
        if(st>end) return nullptr;

        int mid = st + (end-st) / 2;

        TreeNode* root = new TreeNode(nums[mid]); // create the root
        root->left = buildTree(nums, st, mid-1); // build left
        root->right = buildTree(nums, mid+1, end); // build right

        return root;
    }

    // this is the main function given - but we will need to write a helper function to solve this problem.
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }    
};

