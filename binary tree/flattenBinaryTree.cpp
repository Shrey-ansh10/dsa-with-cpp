// LC 114 : Flatten Binary tree to Linked List.

// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.


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

    // Approach 1 : Pre-Order Traversal 
    TreeNode* flattenTree(TreeNode* root){
        if(root == nullptr) return nullptr; 

        TreeNode* leftTail = flattenTree(root->left); // track the Right Sub-Tree's(RST) tail
        TreeNode* rightTail = flattenTree(root->right); // track the tail of Left Sub-Tree(LST)

        if(root->left){ // if left child exist - means LST 
            if(leftTail) leftTail->right = root->right; // if we have a left tail - connect it to the current root's right child
            // this if condition helps to recude some execution time

            root->right = root->left;
            root->left = nullptr;
        }

        // we need to return the tail, so if right tail exist - it will be the last node in LST, if it doesn't exist, then leftTail will be the last node.
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;

    }

    // Approach 2 : Reverse Pre-Order Traversal
    TreeNode* NR = nullptr;
    void flatten(TreeNode* root) {
        
        if(root == nullptr) return;

        // In this approach we first flatten the right sub tree, then left
        // While doing so, we also keep a track of last visited node, and then connect the upper node to this last visited node.
        // This tracking becomes crucial when we traverse a left sub tree and reach to it's last node, which we now need to connect to the right child of the root. 
        flatten(root->right);
        flatten(root->left);

        root->left = nullptr;
        root->right = NR;
        NR = root;
    }
};