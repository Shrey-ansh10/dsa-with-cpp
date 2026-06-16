// LC-236 : Lowest Common Ancestor

#include<iostream>
using namespace std;

#include "../tree_node.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base cases
    if(root == nullptr) return nullptr;
    if(root->val == p->val || root->val == q->val ) return root; // comparing values is faster then comparing addresses

    // recursive calls
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    // Now compare leftLCA and rightLCA, and return an appropriate value
    if(leftLCA && rightLCA) return root;
    else if(leftLCA != nullptr) return leftLCA;
    else return rightLCA;

}