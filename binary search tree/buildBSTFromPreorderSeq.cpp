// LC : 1008 Construct a BST from the given preorder sequence 
// Constrains : 



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

    TreeNode* buildBST(vector<int>& preorder, int& i, int bound, int& len){
        
        if(i >= len || preorder[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[i], nullptr, nullptr);
        i++;

        // create left subtree
        root->left = buildBST(preorder, i, root->val, len);

        // create right subtree
        root->right = buildBST(preorder, i, bound, len); // note that here the bound is not the value at root, but the value at the parent node

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();

        if(len == 0) return nullptr;
        
        if(len == 1){
            TreeNode* root = new TreeNode(preorder[0], nullptr, nullptr);
            return root;
        }
        
        int i = 0; // iterator to iterate through the preorder array
        
        return buildBST(preorder, i, INT_MAX, len);
    
    }
};