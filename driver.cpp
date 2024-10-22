#include "LinkedList.h"
#include "Contact.h"

//function prototypes
void addContact(LL<Contact>*);
void printMenu();
void loadContacts(string, LL<Contact>*);

int main() 
{
    LL<Contact> contactList;
    int choice = 0;


    //placing contacts into the phonebook
    loadContacts("phonebook.txt", &contactList);

    //loop to go through the program 
    do {

        printMenu();

        //take input for switch
        cin >> choice;
        cin.ignore();

        //switch
        switch (choice)
        {
        //iterate forward
        case 1:
        //add contact
        addContact(&contactList);
        break;

        case 2:
        //remove contact
        case 3:
        }
        
    } while (choice = 4);
    //terminate program

    return 0;
}