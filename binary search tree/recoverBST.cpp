// Given a tree, two nodes' value are interchanged which make the tree to violate the property of being a BST.
// Find those nodes in the giben binary tree and swap them to make the tree a BST

#include<iostream>
using namespace std;

#include "../tree_node.h"

TreeNode* prevNode = nullptr; //track the previously visited/ last visited node
TreeNode* fault_1 = nullptr; //we store the node that has the first incorrect value
TreeNode* fault_2 = nullptr; // store the second node with incorrect value


// helper function - helps us find and store the nodes in 'first' and '' 
void inOrder(TreeNode* root){ // perfor inorder traversal - as we know in an inOrder traversal, the values of nodes of BST is always increasing

    if(!root) return; // base case

    inOrder(root->left); // call to left sub tree

    if(prevNode != nullptr && prevNode->val > root->val){ // if the previous is greater than current - that's a note with wrong value
        if(!fault_1) fault_1 = prevNode;
        fault_2 = root;
    }

    prevNode = root; // when we cone to root, we make it the previously visited node

    inOrder(root->right); // call to the right sub tree
}

// the function
TreeNode* recoverBST(TreeNode* root){
    inOrder(root);


    // swap the value of both the faulty nodes
    int temp = fault_1->val;
    fault_1->val = fault_2->val;
    fault_2->val = temp;

    return root; // return the root of tree which is not a proper BST
}


int main(){

    TreeNode* root; // this is the given root of the binary tree with 2 nodes' having wrong values     

    TreeNode* answerRoot = recoverBST(root); // this will be the root that is the root of corrected/recovered BST

    return 0;
}


// n - number of nodes in the tree
// Space Complexity : O(n) - cos of recursion stack
// Time Complexity : O(n) - inorder traversal to all the nodes 

// morris inorder traversal is the way how this can be further optimized for space complexity