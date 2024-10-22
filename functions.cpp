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
    cout << "3. REMOVE CURRENT CONTACT FROM THE PHONEBOOK\n";
    cout << "4. PRINT ENTIRE PHONEBOOK AND TERMINATE PROGRAM\n\n";
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
void removeContact() {

}

//loadContacts
void loadContacts() {

}

//PrintPhonebook
void printPhonebook() {

}