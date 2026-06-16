// LC-102 : Binary tree level order traversal

#include<iostream>
#include<vector>
using namespace std;

#include "../tree_node.h"

vector<vector<int>> levelOrder(TreeNode* root) { // TC - O(n)

        vector<vector<int>> ans; // store node->val
        if (!root) return ans; // if root is null

        queue<TreeNode*> q; // stores node in queue - level order traversal

        q.push(root); // start with root node
        q.push(nullptr); // push nullptr - to track new level
        
        vector<int> levelNodes; // stores node->val for all nodes at this level

        while(!q.empty()){ 
            
            TreeNode* curr = q.front(); // get front
            q.pop(); 

            // this if statement is to track new level of the tree f
            if(curr == nullptr){ // if we encounter nullptr - that's the end of this level
                ans.push_back(levelNodes); // push it to ans vector
                levelNodes.clear();
                
                if(!q.empty()){    
                    q.push(nullptr); // insert null to mark start of new level
                    continue; // move to next element if the queue
                }else{
                    break;
                }
            }
            levelNodes.push_back(curr->val);

            if(curr->left != nullptr) q.push(curr->left); //push left child to queue
            if(curr->right != nullptr) q.push(curr->right); // push right child to queue
        }


        // Approach - 2 
        // vector<vector<int>> ans;
        // if (!root) return ans;
        
        // queue<TreeNode*> q;
        // q.push(root);
        
        // while (!q.empty()) {
        //     int levelSize = q.size(); // initially it will be 1 -> 2 -> 1,2,3,4 -> 1,2,..8 -> ... and so on 
        //     vector<int> levelNodes;
            
        //     for (int i = 0; i < levelSize; i++) {
        //         TreeNode* curr = q.front();
        //         q.pop(); 
                
        //         levelNodes.push_back(curr->val);
                
        //         if (curr->left) q.push(curr->left);
        //         if (curr->right) q.push(curr->right);
        //     }
            
        //     ans.push_back(levelNodes);
        // }

        return ans;
        
    }

