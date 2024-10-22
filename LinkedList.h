#include <iostream>
using namespace std;

void addNewNode(int value);

template<typename T> class Node{
    public:
    T value;
    Node* next;

    //Default constr>uctor for node
    Node() {
        value = 0;
        next = NULL;
    }

    //Parameters for constructor
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

template<typename T> class LL {
    Node* headNode;
    Node* tailNode;

    public:

    LL() {
        //default constrctor for headNode.
        headNode = NULL;
        tailNode = NULL;
    }
    T() {
        
    };

    template<typename T> ~LL();

    template<typname T> bool isEmpty() { 
        if(headNode == NULL) {
            cout << "There are no contacts in your Phonebook!" << endl;
            return true;
        } 
        else {
            return false;
        }
    }

    //Function to add a new node to the list.
    template<typename T> void addNewNode(T value) {
        //Setting up new node
        Node* nn = new Node; //nn (new node)

        nn->value = value;
        nn->next = NULL;

        //Adds note to the front if head is == to null. Set head to nn and also make tail node.
        if (headNode == NULL) {
            headNode = nn;
            tailNode = nn;
            return;
        }
        else {
            //Set tailNode to nn to add at the end of the list.
            tailNode->next = nn;

            //Set the tail to nn
            tailNode->next = nn->next;
        }


    }

    template<typename T>
    void removeNode(int removeValue) {
        Node* nodePtr; //To go through the list and and look for the value passed.
        Node* previousNode; //Pointer to the previous node

        if (headNode == NULL|| !headNode) { 
            cout << "List is empty. The Droids you are looking for are not here!" << endl;
            return;
        }

        if (headNode->value == removeValue) {
            nodePtr = headNode->next;
            delete headNode;
            headNode = nodePtr;
        }

        else {
            nodePtr = headNode;

            while (nodePtr!= NULL && nodePtr->value != removeValue) {
                
            }
        }
    }

    template<typename T>
    void print() {
        Node *nodePtr = headNode;

        //Check if list is empty if the list is empty it will prompt the user to consider adding contacts to the phone book.
        if(nodePtr == NULL) {
            cout << "Phonebook is empty. Please consider adding contacts or loading one from file." << endl;
        }
        //Go through the list as long as nodePtr is not equal to NULL.
        while (nodePtr != tailNode) {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
            
    }

    template<typename T>
    ~LL() {
        Node* nodePtr;
        Node* nextNode;

        //Starting at the beginning of the list.
        nodePtr = headNode;

        //while loop to traverse the list and delete elements in the list where ever nodePtr is.
        while (nodePtr) {
            nextNode = nodePtr->next;

            cout << "Removing " << nodePtr->value << " from Phonebook!" << endl;
            //Deleting the current node
            delete nodePtr;
            //Move to the next node
            nodePtr =  nextNode;
        }
    }

};

