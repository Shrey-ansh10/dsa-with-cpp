// LC-107: Binary Tree Level Order Traversal II

// Only one modification on top of LC-102 
// Just reverse the ans array before returning it

#include<iostream>
#include<vector>
using namespace std;

#include "../tree_node.h"

vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans; 
        if (!root) return ans;   

        queue<TreeNode*> q;

        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes;
            
            for (int i = 0; i<levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop(); 
                
                levelNodes.push_back(curr->val);
                
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            ans.push_back(levelNodes);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }