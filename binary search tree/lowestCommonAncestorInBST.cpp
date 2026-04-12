// LC - 235 : Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        // base case if root can be
        if(root == nullptr) return nullptr;
        // but it is given that both p and q will exist
        if(p->val == root->val || q->val == root->val) return root;


        if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
        
    }
};