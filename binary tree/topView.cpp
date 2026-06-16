// Top view of a Binary Tree

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

#include "../tree_node.h"

// create a tree from preorder and return the root node - O(n) time
TreeNode* buildTree(vector<int>& preorder, int& idx){
    idx++;

    if(preorder[idx] == -1) return nullptr;

    TreeNode* root = new TreeNode(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void topView(TreeNode* root){
    // to print all the nodes that appear from top in a tree - we use the concept of horizontal Dist

    // We will perform level order traversal
    // Will Consider root node as origin node
    // as we traverse : For left child we will reduce the horizontal dist by -1 and for right child by +1
    // This increment and decrement will happen from the root node's distance from origin

    queue<pair<TreeNode*, int>> q;
    map<int, TreeNode*> m; // oredred map to get output in order from left to right
    // NOTE : There can be 2 variants of this type of question. 
    // 1. In which you need to return the references to nodes visible from top view. -> map<int, TreeNode*>
    // 2. In which you need to return/print the value at each node visible from top view -> map<int, int>
    
    q.push({root, 0}); // 2nd thing in pair is the distance from origin - as this is root, which we take as origin, so dist is 0 

    while(!q.empty()){
        pair<TreeNode*, int> curr = q.front();
        TreeNode* currNode = curr.first;
        int dist = curr.second;
        q.pop();

        if(m.find(dist) == m.end()){ // if this dist is not in map - add with corresponding node
            m[dist] = currNode;
        }

        if(currNode->left != nullptr) q.push({currNode->left, dist-1});
        if(currNode->right != nullptr) q.push({currNode->right, dist+1});        
    }

    // after loop ends - print all node->val visible from top
    for(auto it : m){
        cout<< it.second->val ;
    }
    cout << endl;

}

void bottomView(TreeNode* root){
        queue<pair<TreeNode*, int>> q;
    map<int, TreeNode*> m; 
    
    q.push({root, 0});
    
    while(!q.empty()){
        pair<TreeNode*, int> curr = q.front();
        TreeNode* currNode = curr.first;
        int dist = curr.second;
        q.pop();

        if(m.find(dist) == m.end()){
            m[dist] = currNode;
        }else{
            m[dist] = currNode;
        }

        if(currNode->left != nullptr) q.push({currNode->left, dist-1});
        if(currNode->right != nullptr) q.push({currNode->right, dist+1});        
    }

    for(auto it : m){
        cout<< it.second->val ;
    }
    cout << endl;

}


int main(){

    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, 7, -1, -1, -1};

    int idx = -1;
    topView(buildTree(preorder, idx));

    return 0;
}
