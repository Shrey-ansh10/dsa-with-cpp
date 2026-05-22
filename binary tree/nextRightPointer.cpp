// LC-116. Populating Next Right Pointers in Each Node

#include<iostream>
using namespace std;

#include<queue>



class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution1 { // TC : O(n), SC: O(n)
public:
    Node* connect(Node* root) {
        if(root== nullptr) return root;

        queue<Node*> q;

        q.push(root);
        q.push(nullptr);
        Node* curr = nullptr;

        while(!q.empty()){
            if(q.front() != nullptr){
                curr = q.front();
                
                if(curr->left && curr->right){
                    q.push(curr->left);
                    q.push(curr->right);
                }

                q.pop();

                if(q.front() == nullptr){
                    curr->next = nullptr;
                    q.pop();
                    q.push(nullptr);
                }else{
                    curr->next = q.front();
                }

            }else{
                q.pop();
            }
        }
        return root;
        
    }
};

class solution2{ // this one has a better space complexity
public:
    Node* connect(Node* root) { // TC: O(n), SC: O(1)
        if(root == nullptr) return root;

        Node* leftmost = root; //initialize the leftmost with root, this will be to track the level down the tree 
        leftmost->next = nullptr; // as we know before starting that next of root is always nullptr

        while(leftmost->left){
            Node* curr = leftmost; // taking a current pointer whcih will be used to travers throught a level of the tree

            while(curr){//till current is not null

                //connect current's left's next to right
                curr->left->next = curr->right;

                //current's right to left of next's
                if(curr->next) curr->right->next = curr->next->left;
                else curr->right = nullptr; // if it's the rightmost node at a level - point it's next to null

                curr = curr->next; // update the current to the next node on same level
            }
            leftmost = leftmost->left; // moving to the next level downward the tree
        }
        return root;
    }
};