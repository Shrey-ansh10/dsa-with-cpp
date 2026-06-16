// LC-226 : Invert Binary Tree


#include <iostream>
#include "../tree_node.h"
using namespace std;

TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;

        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;

        return root;
}