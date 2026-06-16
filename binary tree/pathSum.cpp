// LC-112 : Path Sum

#include<iostream>
using namespace std;

#include "../tree_node.h"

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;
    
    targetSum -= root->val;

    if(targetSum == 0){
        if(root->left==nullptr && root->right==nullptr) return true;
        // else return false;  - this is a crucial case, if sum becomes 0 but it's not a leaf node - there is a chance that the next node can have value 0
    }
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);  
}
