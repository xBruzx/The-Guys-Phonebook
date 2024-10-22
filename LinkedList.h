#include <iostream>
using namespace std;

void addNewNode(int value);

class Node{
    public:
    int value;
    Node* next;

    //Default constructor for node
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

class LL {
    Node* headNode;

    public:

    LL() {
        //default constrctor for headNode.
        headNode = NULL;
    }

    ~LL();

    bool isEmpty() { 
        if(headNode == NULL) {
            cout << "There are no contacts in your Phonebook!" << endl;
            return true;
        } 
        else {
            return false;
        }
    }

    //Function to add a new node.
    void addNewNode(int value) {
        //Setting up new node
        Node* nn = new Node;
        Node* nodePtr;

        nn->value = value;
        nn->next = NULL;

        //Adds note to the front if head is == to null.
        if (headNode == NULL) {
            headNode = nn;
            return;
        }
        else {
            nodePtr = headNode; //Set nodePtr to headNode to start at the begining of the list.
            
            //traversing the list until we find the end.
            while(nodePtr->next != NULL) {
                nodePtr = nodePtr->next;
            }
            
            nodePtr->next = nn;
        }


    }

    void print() {
        Node *nodePtr = headNode;

        //Check if list is empty if the list is empty it will prompt the user to consider adding contacts to the phone book.
        if(nodePtr == NULL) {
            cout << "Phonebook is empty. Please consider adding contacts or loading one from file." << endl;
        }
        //Go through the list as long as nodePtr is not equal to NULL.
        while (nodePtr != NULL) {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
            
    }
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

