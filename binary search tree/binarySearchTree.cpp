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
    
    // Insert function will be used to actually inser the new nodes in the tree
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


    // This is the function to build the tree - but it will utilize the "insert" function to create the node and place it at the correct position in the tree.
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

    // Search Functionality - Now the search can be implemented in 2 ways
    // 1. Search the value and return that node that contains that value
    // 2. Search the value and return true if that is found.

    bool search(Node* root, int data){
        // if not found and we reach a root of null node
        if(root == nullptr){
            return false;
        }

        // value found
        if(root->val == data){
            return true;
        }
        
        return (data < root->val) ? search(root->left, data) : search(root->right, data);
    }

    // Delete Functionality
    // When we want to delete a node from a BST, there can be 3 cases. But before that we need to find the node in the BST.
    // - So firstly we find the node in the BST.
    // Case 1. The Node we wanna delete has 0 child.
    //      - In this case can simply delete that node and return null, so that the parent node can now mark that particular child as nullptr.
    // Case 2. The Node we wanna delete has 1 child.
    //      - If there is only one child, it's still simple. We just connect the child of the deleting node to the parent of the deleting node. Because we know that in BST, each subtree also follows BST principles and is a BST in itself.
    // Case 3. The Node we wanna delete has 2 children.
    //      - This is were the main work comes.
    //      - So first, we find the In-order Successor(IS) of the node to be deleted. 
    //      - Then we replace the node's val with the IS's value. 
    //      - Then we delete the IP node. (The IS node will always fall in the Case 1 or 2 category. Cos the IS of a node in BST is the leftmost node in the right subtree.)

    Node* deleteNode(Node* root, int data){ // we have to use 'deleteNode' name as 'delete' is a keyword
        
        // base case 
        if(root == nullptr){ // or (root == nullptr)
            return nullptr;
        }

        // search along the way
        if(data < root->val){ // search left if val is smaller than root's val
            root->left = deleteNode(root->left, data);
        } else if(data > root->val){ // search right if val is greater than root's val
            root->right = deleteNode(root->right, data);
        } else{  // when the current node is to be deleted 
            // The first if-else bolck will cover Case 1 and 2, because in both case we have to return a value - null or not null.
            if(root->left == nullptr){ 
                Node* temp = root->right; // Store right in the temp - the right can be a value of null. But it doesn't matter as we will follow the rules we discussed earlier. 
                delete root;
                return temp;
            } else if(root->right == nullptr){ 
                Node* temp = root->left;
                delete root;
                return temp;
            } else { // Case 3
                // Find IS and store it
                Node* IS = findInorderSuccessor(root->right);

                // replace the node/root's value with the IS's value
                root->val = IS->val;

                // Delete IS
                root->right = deleteNode(root->right, IS->val);
            }
        }
        return root; 
    }

    // helper function that will help the deleteNode function's CASE-3 to find the In-order Successor
    Node* findInorderSuccessor(Node* root){
        while(root != nullptr && root->left != nullptr){
            root = root->left;
        }
        return root;
    }

};


int main(){

    BST tree; // create a tree object

    vector<int> inputs = {4,5,3,6,2,10,9,11,8,1};

    // Build tree - store the returned root in this root pointer
    Node* root = tree.build(inputs);

    // Print tree
    tree.inorder(root);
    cout << endl;

    // Search Functionality test by searching a value
    
    // Readable way 
    bool ans = tree.search(root, 15);
    if(ans) cout << "True" << endl;
    else cout<< "False" << endl;

    // short hand way
    tree.search(root, 5) ? cout << "True" << endl : cout <<"False" << endl;


    // Try Delete functionality
    root = tree.deleteNode(root, 5);
    cout << "Tree after deleting 5 : ";
    tree.inorder(root);
    cout << endl;
    cout << "Root Val :" << root->val << endl;
    cout << endl;
    
    root = tree.deleteNode(root, 6);
    cout << "Tree after deleting 6 : ";
    tree.inorder(root); 
    cout << endl;
    cout << "Root Val :" << root->val << endl;
    cout << endl;
    
    root = tree.deleteNode(root, 4);
    cout << "Tree finally : ";
    tree.inorder(root);
    cout << endl;
    cout << "Root Val : " << root->val << endl;
    cout << endl;


}