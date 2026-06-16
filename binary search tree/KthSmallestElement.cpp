// 230. Kth Smallest Element in a BST

#include<iostream>
using namespace std;

#include "../tree_node.h"

class Solution {
public:
    TreeNode* ans = nullptr;
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        // base case
        if(root == nullptr) return 0;

        // left traversal
        if(root->left){
            // this is optional - one can do as I've done in the right subtree traversal (below)
            int leftAns = kthSmallest(root->left, k);
            if(leftAns!=0) return leftAns;
        }

        // at root
        count++;
        if(k==count){
            ans = root; 
            return root->val;
        }

        // right traversal
        if(root->right) kthSmallest(root->right, k);

        return ans? ans->val : 0;
    }
};
