#include <iostream>
using namespace std;

void addNewNode(int value);

template<typename N> class Node{
    public:
    N value;
    Node* next;

    //Default constructor for node
    Node() {
        N value;
        next = NULL;
    }

    //Parameters for constructor
    Node(N value) {
        this->value = value;
        this->next = NULL;
    }
};

template<typename LI> class LL {
    private:
    Node<LI>* headNode;
    Node<LI>* tailNode;


    public:
    LL() {
        //default constrctor for headNode.
        headNode = NULL;
        tailNode = NULL;
    }

    //destructor for linked list.
    ~LL() {

        Node<LI>* nodePtr;
        Node<LI>* nextNode;

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

    //Operations for linked list.
    bool isEmpty();
    int getListLength();
    void addNewNode(LI);
    void printContact(int);
    void insertNode(int, Node<LI>*);
    Node<LI>* getNodeValue(int);
    void insertionSort();

    void removeNode(Node<LI>* nodePackage) {
        //cout << "\nYou reached the removeNode() function!\n";
        Node<LI>* nodePtr; //To go through the list and and look for the value passed.
        Node<LI>* previousNode; //Pointer to the previous node

        //If the list is empty, promt the user no contacts are in the list.
        if (headNode == NULL|| !headNode) { 
            cout << "List is empty. The Droids you are looking for are not here!" << endl;
            return;
        }

        //Search for the value passed to delete the node specified by the user.
        if (headNode == nodePackage) {
            nodePtr = headNode->next;
            delete headNode;
            headNode = nodePtr;
        }


        else {

            //make nodePtr head of the list.
            nodePtr = headNode;

            //Make sure we skips nodes that don't have the value that is passed.
            while (nodePtr!= NULL && nodePtr != nodePackage) {
                previousNode = nodePtr;
                
                //Move to next node
                nodePtr = nodePtr->next;
                
            }
        }
    }

    void print() {
        Node<LI>* nodePtr = headNode;

        //Check if list is empty if the list is empty it will prompt the user to consider adding contacts to the phone book.
        if(nodePtr == NULL) {
            cout << "Phonebook is empty. Please consider adding contacts or loading one from file." << endl;
        }

        if (nodePtr != NULL) {
            //Go through the list as long as nodePtr is not equal to NULL.
            while (nodePtr != NULL) {
                //Outputs list of contacts
                cout << nodePtr->value << endl;
                //Move to next node.
                nodePtr = nodePtr->next;
            }
        }
            
    }


};


template <typename LI>
bool LL<LI>::isEmpty() { 
    if(headNode == NULL) {
        cout << "There are no contacts in your Phonebook!" << endl;
        return true;
    } 
    else {
        return false;
    }
}




//Function to add a new node to the list. (Append to the list.)
template <typename LI>
void LL<LI>::addNewNode(LI value) {
    //Setting up new node
    Node<LI>* nn = new Node<LI>; //nn (new node)

    nn->value = value;
    nn->next = NULL;

    //Adds note to the front if head is == to null. Set head to nn and also make tail node.
    if (headNode == NULL) {
        headNode = nn;
        tailNode = nn;
    }
    else {
        //Set current tailNode next node to nn to add at the end of the list.
        tailNode->next = nn;

        //Set the tail to nn
        tailNode = nn;
    }

}

template <typename LI>
int LL<LI>::getListLength() {
    int counter = 0;
    Node<LI>* nodePtr;
    nodePtr = headNode;

    cout << "You got here." << endl;

    //go through the list of contacts and count each one to get the length of the Phonebook
    while (nodePtr != NULL) {
        counter++;
        nodePtr = nodePtr->next;

        cout << counter << endl;
        cout << nodePtr->value << endl;
    }

    cout << "You got before the return." << endl;
    return counter;
}

//function to print the contact information of the value given in the phonebook, and not the whole list.
template <typename LI>
void LL<LI>::printContact(int it) {

    Node<LI>* nodePtr = headNode; //node ptr set to head of list.
    Node<LI>* nodePackage = getNodeValue(it); 

    //if the head is set to null then that means that the list is empty.
    if (headNode == NULL) {
        cout << "Phonebook is empty. Please consider adding contacts" << endl;
        return;
    }


    //Search the list for the contact passed through.
    while (nodePtr != NULL) {
        if (nodePtr->value == nodePackage->value) {
            cout << nodePackage->value << endl;
            return;
        }
        else {
            nodePtr = nodePtr->next;
        }
    }
}

template <typename LI>
Node<LI>* LL<LI>::getNodeValue(int pos) {
    Node<LI>* nodePtr;

    //If the list is empty, we return NULL.
    if(!headNode) {
        cout << "Empty list please add some contacts to the phonebook." << endl;
        return NULL;
    }

    else {
        //If we pass 0 then we just show the head value.
        if(pos == 0) {
            return headNode;
    }
        nodePtr = headNode;
        int currentPos = 0; //temp value to keep track of where we are in the list.
        //loop through the list to find the position we passed through.
        while(pos >= currentPos && nodePtr != NULL) {

        //If we find the position return the value of the nodePtr.
        if(pos == currentPos) {

            return nodePtr;
        }

        //if we do not find the position then we increment and check again.
        currentPos++;
        nodePtr = nodePtr->next;

        }
    }

    return headNode;

}

template <typename LI>
void LL<LI>::insertNode(int nodePos, Node<LI>* nodeValue){
    //cout << "\nYou reached the insertNode() function!\n";
    Node<LI>* nodePtr;
    Node<LI>* nn;

    nn = new Node<LI>;
    nn->value = nodeValue->value;

    if(!headNode) {

        //If there is already a node at position zero we move on to another position. If there is not a node there currently we place it there.
        if(nodePos != 0) {
            cout << "Unable to insert contact at position: " << nodePos << endl;
        }

        headNode = nn;
        tailNode = nn;
    }
    else {
        nodePtr = headNode; //set nodePtr to headNode
        int nodeCounter = 0; //temp node counter to keep track until we find nodePos
        if(nodePos == 0) {
            //setting (new node)nn->next = headNode; which will make the new head node as the new node.
            nn->next = headNode;
            headNode = nn;
        }
        else {
            //Keep searching the list until nodeCounter is reached
            while(nodePtr != NULL && nodeCounter < nodePos){
                nodeCounter++;
                nodePtr = nodePtr->next;

            }

            //appending node to the end of the list.
            if (nodePtr == tailNode) {
                tailNode->next = nn;
                tailNode = nn;

            }

            //nn next is now nodePtr next and nodePtr is now tail
            nn->next = nodePtr->next;
            nodePtr->next = nn;
        }
    }

}

template<typename LI>
void LL<LI>::insertionSort() {
    Node<LI>* key;
    int j;

    for (int i = 1; i < getListLength(); i++)
    {
        key = getNodeValue(i);
        j = i - 1;

        while (j >= 0 && getNodeValue(j)->value > key->value)
        {
            j = j - 1;
        }
    }
}





















/*
void LL<LI>::insertionSort() {
    //cout << "\nYou reached the insertionSort() function!\n";
    Node<LI>* key;
    Node<LI>* arr;
    int j;
    int size = getListLength();

    for(int i = 1; i < size; i++) {
        key = getNodeValue(i);
        j = i-1;

        while (j >= 0 && getNodeValue(j) > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }

        //Remove the key and then insert it to the correct part of the list.
        removeNode(key);
        insertNode(j+i, key);
    }


}
*/