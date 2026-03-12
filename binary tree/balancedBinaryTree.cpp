// Given the binary tree, check if it is height balanced.

#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int height(TreeNode* root){

        if(root == nullptr) return 0;

        // we check the height-balance of left and right subtree as we go down 
        
        int leftHeight = height(root->left); // recursive call on the left subtree
        if(leftHeight == -1) return -1; // when backtracking we check if something is wrong down this sub tree, if there is some misbalance, from here itself we return -1, and it will propogate upward, making sure all the node and all subtree are height-balanced

        int rightHeight = height(root->right); // recursive call on the right subtree
        if(rightHeight == -1) return -1; // check while returning

        // if at any node the difference between leftheight and rightheight goes beyond 1, we return -1 from there. -1 acts as a flag instead of directly returning a bool value, -1 help to utilize this helper function and still keep a chek on each nodes height-balance
        if(abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
