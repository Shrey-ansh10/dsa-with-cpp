#ifndef SORTED_ARRAY_TO_BST_H
#define SORTED_ARRAY_TO_BST_H

#include <vector>
#include "tree_node.h"

using namespace std;

class sortedArrayToBSTSol{
    public:
        TreeNode* buildTree(vector<int>& nums, int st, int end);
        TreeNode* sortedArrayToBST(vector<int>& nums);
};

#endif