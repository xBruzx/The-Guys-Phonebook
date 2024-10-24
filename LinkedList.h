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

    //template<typename T>
    void removeNode(int removeValue) {
        Node* nodePtr; //To go through the list and and look for the value passed.
        Node* previousNode; //Pointer to the previous node

        //If the list is empty, promt the user no contacts are in the list.
        if (headNode == NULL|| !headNode) { 
            cout << "List is empty. The Droids you are looking for are not here!" << endl;
            return;
        }

        //Search for the value passed to delete the node specified by the user.
        if (headNode->value == removeValue) {
            nodePtr = headNode->next;
            delete headNode;
            headNode = nodePtr;
        }


        else {

            //make nodePtr head of the list.
            nodePtr = headNode;

            //Make sure we skips nodes that don't have the value that is passed.
            while (nodePtr!= NULL && nodePtr->value != removeValue) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
                
            }
        }
    }

    void print() {
        Node* nodePtr = headNode;

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

    template<typename T> void printContact(T value) {

        Node* nodePtr = headNode;
        Node* previousNode;

        if (headNode == NULL) {

            cout << "Phonebook is empty. Please consider adding contacts" << endl;

        }

        //Search the list for the contact passed through.
        while (nodePtr != NULL && nodePtr->value != value) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;

            if (nodePtr-value = value) {
                cout << nodePtr->value << endl;
            }
        }
    }

    int getListLength() {
        int counter = 0;
        Node* nodePtr;

        nodePtr = headNode;

        //go through the list of contacts and count each one to get the length of the Phonebook
        while (!= tailNode) {
            counter ++
            nodePtr = nodePtr->next;
            if (nodePtr == tail) {
                counter++
            }
        }

        return counter;
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

