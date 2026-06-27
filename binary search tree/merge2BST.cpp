// Merget two BST

#include <iostream>
using namespace std;

#include "binary search tree/sortedArrayToBST.h" // importing the implementation of building a BST for a Sorted array

sortedArrayToBSTSol sol; // create a object of the class where we have the implementation, so we can access the methods and use it here.
// created this object at global scope so that all the functions can access it


//merge 2 arrays in a sorted array
vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2){

    int len1 = arr1.size();
    int len2 = arr2.size();

    vector<int> ans = {};

    int i = 0;
    int j = 0;

    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else if(arr1[i] > arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }else{
            // in case both the different BST's have a common element we will have to skip one element as we know BST can not have dulpicate elements.
            ans.push_back(arr1[i++]);
            j++;
        }
    }

    while(i < len1){
        ans.push_back(arr1[i++]);
    }

    while(j < len2){
        ans.push_back(arr2[j++]);
    }

    return ans;
}

// return an array containing inorder sequence of a BST
void inOrder(TreeNode* root, vector<int>& arr){
    
    if(root == nullptr) return ;

    if(root->left == nullptr && root->right == nullptr){
        arr.push_back(root->val);
        return;
    }

    inOrder(root->left, arr);
    arr.push_back(root->val);
    inOrder(root->right, arr);

}

// function to merge 2 BST
TreeNode* merge(TreeNode* root1, TreeNode* root2){

    // get the inorder sequence of both the tree
    vector<int> inOrder1 = {}; // empty arr 
    inOrder(root1, inOrder1);
    
    vector<int> inOrder2 = {}; // empty arr 
    inOrder(root2, inOrder2);

    vector<int> mergedArr = mergeTwoSortedArrays(inOrder1, inOrder2); // pass both the sorted arrays to the function which will merge them in sorted way

    // Now call the function that will build the BST and return the root node to us
    // we will build a balanced BST - for that we will use the class where we already implemented this solution

    return sol.sortedArrayToBST(mergedArr);
}

// Inorder traversal
void inorder(TreeNode* n) {
    if (!n) return;

    inorder(n->left); 
    cout << n->val << ' ';
    inorder(n->right);
}

int main(){

    vector<int> tree1 = {1,3,5,7,9,11,13,15,17,19}; // we will use this vector to create the first BST
    TreeNode* root1 = sol.sortedArrayToBST(tree1); // root for the first BST

    vector<int> tree2 = {2,4,6,8,10,12,14,16,18,19}; // use this to create 2nd tree
    TreeNode* root2 = sol.sortedArrayToBST(tree2); // root for the second BST

    TreeNode* answerNode = merge(root1, root2); // pass both the roots in the merger function to merge both BSTs

    // do a in-order traversal on it
    inorder(answerNode);

    return 0;
}