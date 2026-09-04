// implementing linkedlist from scratch

#include<iostream>
using namespace std;

class Node{ //this class will solely be used to create a new node in list

public: // properties of the new node
    int data; // data to store in that node
    Node* next; // pointer to next data node - will always be null for every new node

    Node(int val){ //constructor - creates the node object and assigning value to it's variable properties
        data = val; // storing the data in it
        next = nullptr; // pointer to next node - will always be null when new node is created
    }
};

// new class called List to manage and create a list
class List{ 
    Node* head; // head pointer to point to the start of the list
    Node* tail; // tail pointer to point the last element of list

    // clear function will be used by destructor, to delete the list and clear the memory
    void clear() {
        Node* current = head;

        // deleting all the nodes
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        // setting the head and tail to null
        head = nullptr;
        tail = nullptr;
    }
    
public:
    List(){ // initlizing the list
        head = tail = nullptr;  // both head and tail point to NULL meaning the list is empty
    }

    // return head
    Node* getHead(){
        Node* copyHead = head;
        return copyHead;
    }

    Node* getTail(){
        Node* copyTail = tail;
        return copyTail;
    }

    // Functions we need for out list
    // 1. push_back() : to add elements to the end/back of the list

    // creating methods/function to insert elements at the end of the list
    void push_back(int val){ // O(1)
        Node* newNode = new Node(val);

         // Case 1: when there's no element in the list
        if(tail == nullptr){
            head = tail = newNode;  //both point to this newly created node
            return;
        }else{ // Case 2: atleast 1 element or more
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 2. pop_back() : to remove the last elements of the list
    void pop_back(){ // O(n)
        // to perform deletion from the end of the linked list, we will need to traverse from head to second last node of the list; update the pointer of this second last node to NULL; store the last node in some tempStore, update tail node, delete the tempStore;
        
        if(tail == nullptr){
            cout << "empty linked list" << endl;
            return ;
        }else{
            Node* temp = head->next; // create a temp pointer to traverse through the list
            // can also use => Node* temp = head;
            while(temp->next != tail){ // when we don't have tail ptr we can use -> while(temp->next->next == NULL)
                temp = temp->next; // keep updating temp with next node
            }

            // Approach 1 : to delete last node and update tail
            // tail = temp; // updating tail to second last element
            // temp = temp->next; //storing the last node in temp
            // tail->next = NULL; // update tail's next pointer to NULL 
            // delete temp; // delete the last node - temp will point to some garbage value

            // Approach 2 : to delete last node and update tail
            temp->next = nullptr; // remove connection with the last element 
            delete tail; // delete the tail node - but tail pointer still stays and points to some garbage value
            tail = temp; // therefore update the tail pointer to temp           
        }

    }

    // unlike vectors, in lists we can insert and delete elements from front as well.
    // 3. push_front() : O(1)
    void push_front(int val){ //takes in the value/data inserted at a node
        // creating a dynamic object
        Node* newNode = new Node(val); // created a pointer of type Node, that points to newly created node object. The new node is created using Node class
            
        // Case 1: when there's no element in the list
        if(head == nullptr){
            head = tail = newNode;  //both point to this newly created node
            return;
        }else{  // Case 2 : list contains one or more object
            newNode->next = head;
            head = newNode; // update the head
            return;
        }
    }
    
    // 4. pop_front() :
    void pop_front(){ //O(1)
        if(head == nullptr){
            cout << "empty linked list" << endl;
            return ;
        }else{
            Node* temp = head; //creating a temp pointer to point at first node - this will be used to delete data from the node
            head = head->next; // updating the head to the next node in the list
            temp->next = nullptr; // removing pointer to next node
            delete temp; // delete node that temp points at
        }
    }

    // print function to print the linkedlist
    void printLL(){ //O(n)
        Node* temp=head;
        while(temp != nullptr){
            cout << temp->data << " " ; //print the data at this node
            temp = temp->next; // update temp pointer
        }
        cout << endl;
    }


    // function to add a new node in middle of linkedlist
    void addNodeInMiddle(int val, int pos){ //O(n)
        if(pos < 0) return;

        if(pos == 0){
            push_front(val);
            return;
        } 

        Node* newNode = new Node(val); // created a new node, this will be inserted in the linked list
        Node* temp = head; // pointer

        for(int i=0; i<pos-1; i++){ 
            if(temp->next == nullptr){ 
                cout << "Invalid position!!!\n" << pos <<  " exceeds end of LL. \nMax value of pos can be " << i+1 << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

    }

    // search an element in LL
    void search(int val){ // O(n)
        Node* temp = head;
        int pos=1;
        while (temp != nullptr){
            if(temp->data == val){
                cout << "Found Value at position : " << pos << endl;
            }
            temp = temp->next; //moving to next element
            pos++; //increment 
        }
        if(temp == nullptr){
            cout << "value doesn't exist in the LL." << endl;
        }
    }

    // Destructor
    ~List(){
        clear(); // calls the clear function which deletes all the nodes in the list
    }

};