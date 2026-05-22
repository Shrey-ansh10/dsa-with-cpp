// LC-116. Populating Next Right Pointers in Each Node

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