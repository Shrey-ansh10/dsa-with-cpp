// LC-226 : Invert Binary Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;

        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;

        return root;
}