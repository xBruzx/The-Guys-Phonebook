#include "LinkedList.h"
#include "Contact.h"

//function prototypes
void addContact(LL<Contact>*);
void printMenu();
void printPhonebook(LL<Contact>*);
void loadContacts(string, LL<Contact>*);
void removeContact(LL<Contact>*);

int main() 
{
    LL<Contact> contactList;
    int choice = 0;
    int it = 0;


    //placing contacts into the phonebook
    loadContacts("phonebook.txt", &contactList);

    //sort phonebook in alphabetical order by last name
    contactList.insertionSort();
    //loop to go through the program 
    do {

        contactList.printContact(it);
        printMenu();

        //take input for switch and validate input
        cin >> choice;
        while (cin.fail() || (choice < 1 || choice > 5))
        {
            cout << "Error! Enter a valid input.\n\n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> choice;
        }
        cin.ignore();

        //switch
        switch (choice)
        {
            //iterate forward
            case 1:
                    if (it >= (contactList.getListLength() - 1))
                    {
                        it = 0;
                    }
                    else
                    {
                        it++;
                    }
                    break;

            case 2:
                    //add contact
                    addContact(&contactList);
                    //resort phonebook
                    contactList.insertionSort();
                    break;

            case 3:
        
                    //remove a contact
                    removeContact(&contactList);
                    break;
            
            case 4:
                    //print phonebook
                    printPhonebook(&contactList);
                    break;
        }
        
    } while (choice != 5);
    //terminate program

    printPhonebook(&contactList);

    return 0;
}