// LC-103 : Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

#include<iostream>
#include<vector>
using namespace std;

#include "../tree_node.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

// 1. Perform Normal Level order traversal and store levels in seperate vectors
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<TreeNode*> q; // queue
    q.push(root); // start with root
    // q.push(nullptr); // seperates levels
    // vector<int> levelNodes; // stores current level nodes

    // while(!q.empty()){
    //     TreeNode* curr = q.front();
    //     q.pop();

    //     if(curr == nullptr){
    //         ans.push_back(levelNodes);
    //         levelNodes.clear();

    //         if(!q.empty()){
    //             q.push(nullptr); //level ends - new level nodes will be pushed to queue, so befor that insert a nullptr to seperate levels
    //             continue;
    //         }else{
    //             break;
    //         }
    //     }
        
    //     levelNodes.push_back(curr->val);

    //     if(curr->left) q.push(curr->left);
    //     if(curr->right) q.push(curr->right);
    // }

    // Approach 2
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

    // 2. reverse every second vector in the answer array
    for(int i=0; i<ans.size(); i++){
        if(i%2){
            reverse(ans[i].begin(), ans[i].end());
        }
    }
return ans;

}