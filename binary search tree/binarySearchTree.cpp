//  The good thing is that the class node remains the same as binary tree's node.
//  Just the creating of the whole tree's logic changes


#include<iostream>
#include<vector>
using namespace std;

class Node{

public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};


class BST{

public:
    
    // insert function will be used to actually inser the new nodes in the tree
    Node* insert(Node* root, int data){
        if(root == nullptr){ // or !root
            return new Node(data); // create a new node and return it
        } 

        // if someone try to insert duplicate value - return null and discard that value
        if(root->val == data){
            cout << "Duplicate values cannot be inserted in BST." << endl;
            return root;
        }
        if(data < root->val){
            root->left = insert(root->left, data);
        }else{
            root->right = insert(root->right, data);
        }

        return root;
    } 


    // this is the function to build the tree - but it will utilize the "insert" function to create the node and place it at the correct position in the tree.
    Node* build(vector<int>& input){
        Node* root = nullptr; // create a root node as nullptr

        for(int i : input){
            root = insert(root, i);
        }
        return root;
    }

    void inorder(Node* n) {
    if (!n) return;
    inorder(n->left);
    cout << n->val << ' ';
    inorder(n->right);
}

};


int main(){

    BST tree; // create a tree object

    vector<int> inputs = {4,5,3,6,2,10,9,11,8,1};

    // build tree - store the returned root in this root pointer
    Node* root = tree.build(inputs);

    // print tree
    tree.inorder(root);

}