// LC-98 : Validate BST : Given a binarty tree, validate/check if it is a valid BST. 

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

    bool validateBinTree(TreeNode* root, long long min, long long max){
        // base case 
        if(root == nullptr) return true;

        // false cases - where we immediately return false
        // if(root->val != min || root->val != max) return false; // this should be used when there is no check if the values at each node in a given range or not
        if(root->val <= min) return false;
        if(root->val >= max) return false;
        
        // if we dont stick in base case - recursive calls on left and right sub tree
        return (validateBinTree(root->left, min, root->val) && validateBinTree(root->right, root->val, max));
    }

    bool isValidBST(TreeNode* root) {
        return validateBinTree(root, LLONG_MIN, LLONG_MAX); // call the helper function and return it's value
        
        // The constrains of this problem statement states the value on each node will be INT_MIN <= node->val <= INT_MAX
        // So that means we can use Long long in our solution, but before that there is someones responsibility to check if the value at each node is in that range. 

        // If we change the condition a little bit to INT_MIN < node->val < INT_MAX , using INT_MIN and INT_MAX will work perfectly fine. 
        // It's just that the as soon as the <= comes in the constrain, that's when INT_MIN and INT_MAX no longer will work
    }
};