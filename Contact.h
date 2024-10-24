#ifndef CONTACT_H
#define CONTACT_H

//Finsihed

#include <iostream>
#include <string>
using namespace std;

class Contact 
{
    //attributes
    private:
        string firstName;
        string lastName;
        string email;
        string address;
        string phoneNum;
        int areaCode;

    //methods
    public:
        //getters
        string getFirstName() const;
        string getLastName() const;
        string getEmail() const;
        string getAddress() const;
        string getPhoneNum() const;
        int getAreaCode() const;

        //setters
        void setFirstName(string);
        void setLastName(string);
        void setEmail(string);
        void setAddress(string);
        void setPhoneNum(string);
        void setAreaCode(int);

        //overloaded operators
        bool operator==(const Contact& right_comparison)
        {
            return this->lastName == right_comparison.lastName;
        }
        bool operator<(const Contact& right_comparison)
        {
            return this->lastName < right_comparison.lastName;
        }
        bool operator>(const Contact& right_comparison)
        {
            return this->lastName > right_comparison.lastName;
        }
        
        friend ostream& operator<<(ostream& os, Contact& cntc)
        {
            os << "(" << cntc.firstName << ", " << cntc.lastName << ", " << cntc.email << ", " <<
            cntc.address << ", " << cntc.phoneNum << ", " << cntc.areaCode << ")";
            return os;
        }
};

//getters
string Contact::getFirstName() const
{
    return this->firstName;
}

string Contact::getLastName() const
{
    return this->lastName;
}

string Contact::getEmail() const
{
    return this->email;
}

string Contact::getAddress() const
{
    return this->address;
}

string Contact::getPhoneNum() const
{
    return this->phoneNum;
}

int Contact::getAreaCode() const
{
    return this->areaCode;
}

//setters
void Contact::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Contact::setEmail(string email)
{
    this->email = email;
}

void Contact::setAddress(string address)
{
    this->address = address;
}

void Contact::setPhoneNum(string phoneNum)
{
    this->phoneNum = phoneNum;
}

void Contact::setAreaCode(int areaCode)
{
    this->areaCode;
}

#endif