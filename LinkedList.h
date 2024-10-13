#include <iostream>
using namespace std;

void addNewNode(Node* headNode, int node);

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
        //Function to add a new node.
        void addNewNode(Node* headNode, int node) {
            //Setting up new node
            Node* nn = new Node;
            //Adds note to the front if head is == to null.
            if (headNode == NULL) {
                headNode = nn;
                return;
            }

            nn->next = headNode;
            headNode = nn;

        }

        void print() {
            Node *head = headNode;

            //Check if list is empty
            if(headNode == NULL) {
                cout << "Phonebook is empty. Please consider adding contacts or loading one from file." << endl;
            }
            //Go through the list.
            while (head != NULL) {
                cout << head->value << endl;
                head = head->next;
            }
            
        }

};

