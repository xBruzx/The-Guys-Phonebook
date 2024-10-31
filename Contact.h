#ifndef CONTACT_H
#define CONTACT_H

//Finsihed contacts.

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
        string getFirstName() const
        {
            return this->firstName;
        }
        string getLastName() const
        {
            return this->lastName;
        }
        string getEmail() const
        {
        return this->email;
        }
        string getAddress() const
        {
            return this->address;
        }
        string getPhoneNum() const
        {
            return this->phoneNum;
        }

        int getAreaCode() const
        {
            return this->areaCode;
        }



        //setters
        void setFirstName(string firstName)
        {
            this->firstName = firstName;
        }

        void setLastName(string lastName)
        {
            this->lastName = lastName;
        }

        void setEmail(string email)
        {
            this->email = email;
        }

        void setAddress(string address)
        {
            this->address = address;
        }

        void setPhoneNum(string phoneNum)
        {
            this->phoneNum = phoneNum;
        }
        void setAreaCode(int areaCode)
        {
            this->areaCode;
        }



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

#endif