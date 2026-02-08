// LC-662 : Maximum Width of Binary Tree
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

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

int widthOfBinaryTree(TreeNode* root) { 

    int maxWidth = 0;

    queue<pair<TreeNode*, unsigned long long>> q; // create a queue to store the pair of TreeNode* and it's CBT Index 
    q.push({root, 0});

    while(!q.empty()){
        int leftIdx = q.front().second;
        int rightIdx = q.back().second;
        maxWidth = max(maxWidth, (int)(rightIdx - leftIdx + 1));

        int currLevelSize = q.size(); // Take the size of current level
        for(int i = 0; i < currLevelSize; i++){ // Process all the child nodes of nodes in the current level
            pair<TreeNode*, unsigned long long> curr = q.front();
            q.pop();

            if(curr.first->left) q.push({curr.first->left, 2*curr.second+1});
            if(curr.first->right) q.push({curr.first->right, 2*curr.second+2});

        }
    }
    return maxWidth;
}

// TC : O(n) - where n is the number of nodes in the tree
// SC : O(maxWidth) - means at any level the max nodes in the queue will be equal to width, 
// but in words case we can say the TC -> O(n/2) -> O(n)
