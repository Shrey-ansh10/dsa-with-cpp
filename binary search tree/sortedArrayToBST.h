#ifndef SORTED_ARRAY_TO_BST_H
#define SORTED_ARRAY_TO_BST_H

#include <vector>
#include "tree_node.h"

class sortedArrayToBSTSol{
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums);

    private:
        TreeNode* buildTree(vector<int>& nums, int st, int end);
};

#endif