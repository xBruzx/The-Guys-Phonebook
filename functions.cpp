#include <iostream>
#include <fstream>
#include "Contact.h"
#include "LinkedList.h"
using namespace std;

//printMenu
void printMenu() 
{
    cout << "\n1. DISPLAY NEXT CONTACT\n";
    cout << "2. ADD A NEW CONTACT TO THE PHONEBOOK\n";
    cout << "3. REMOVE A CONTACT FROM THE PHONEBOOK\n";
    cout << "4. PRINT ENTIRE PHONEBOOK TO SCREEN\n";
    cout << "5. PRINT ENTIRE PHONEBOOK AND TERMINATE PROGRAM\n\n";
}

//addContact
void addContact(LL<Contact>* contactList)
{
    //ititializing all variables
    Contact newContact;
    string addFirstName;
    string addLastName;
    string addEmail;
    string addAddress;
    string addPhoneNum;
    int addAreaCode;

    //taking user input for the contact
    cout << "What is the person's first name?\n";
    getline(cin, addFirstName);
    newContact.setFirstName(addFirstName);

    cout << "What is the person's last name?\n";
    getline(cin, addLastName);
    newContact.setLastName(addLastName);

    cout << "What is the person's email address?\n";
    getline(cin, addEmail);
    newContact.setEmail(addEmail);

    cout << "What is the person's physical address?\n";
    getline(cin, addAddress);
    newContact.setAddress(addAddress);

    cout << "What is the person's phone number (excluding area code, ideally in XXX-XXXX format)?\n";
    newContact.setPhoneNum(addPhoneNum);
    cout << "What is the person's area code?\n";
    cin >> addAreaCode;
    cin.ignore();

    contactList->addNewNode(newContact);


}

//removeContact
void removeContact(LL<Contact>* ptr) {

    int userInput;

    //take user input
    "\nWhat contact do you want to delete (enter a number that matches the node)?";
    cin >> userInput;

    //validate input
    while (userInput < 0 || userInput >= ptr->getListLength())
    {
        "\nNo contact at this point. Please enter a valid input.\n";
        cin.ignore();
        cin >> userInput;
    }

    //call function
    ptr->removeNode(userInput);

}

//loadContacts
void loadContacts(string filename, LL<Contact>* listContactPtr) {
    ifstream contactsFile;
    string line;
    Contact myContacts;
    int var;

    contactsFile.open(filename, ios::in);
    if (contactsFile.is_open())
    {
        while (getline(contactsFile, line, '#'))
        {
            myContacts.setFirstName(line);
            getline(contactsFile, line, '#');
            myContacts.setLastName(line);
            getline(contactsFile, line, '#');
            myContacts.setEmail(line);
            getline(contactsFile, line, '#');
            myContacts.setAddress(line);
            getline(contactsFile, line, '#');
            myContacts.setPhoneNum(line);
            getline(contactsFile, line, '#');
            var = stoi(line);
            myContacts.setAreaCode(var);

            listContactPtr->addNewNode(myContacts);
        }
    }
    else
    {
        cout << "ERROR: FILE COULD NOT OPEN.";
    }
    contactsFile.close();
}

//Print the entire list of contacts
void printPhonebook(LL<Contact>* phonebookList) {
    phonebookList->print(); 
}


