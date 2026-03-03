// Moris In-order traversal

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

vector<int> ans;

TreeNode* findIP(TreeNode* root, TreeNode* currentNode){ // helper function to create 
    while(root->right != nullptr && root->right != currentNode){
        root = root->right;
    }
    return root;
}

vector<int> inorderTraversal(TreeNode* curr){ // using morris inorder traversal

    while(curr != nullptr){
        
        if(curr->left == nullptr){ // in case there is no further left child
            ans.push_back(curr->val); // put the current node to ans
            curr = curr->right; // move to right node and traverse the right sub tree
        }else{
            TreeNode* IP = findIP(curr->left, curr); // call the helper function to find the inorder predecessor

            if(IP->right == nullptr){ //
                IP->right = curr; // connect the IP to the root node
                curr = curr->left; // move current to left child - for traversing the whole left tree
            }else{
                IP->right = nullptr; // delete the connection to root
                ans.push_back(curr->val); // put curr node to ans
                curr = curr->right; // move it to the right
            }
        }
    }
    return ans;
}


