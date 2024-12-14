#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
using std::string;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNb;
    string secret;
public:
    Contact();
    // ~Contact();

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setNickname(string nickame);
    void setPhoneNb(string phoneNb);
    void setSecret(string secret);

    string getFirstName();
    string getLastName();
    string getNickname();
    string getPhoneNb();
    string getSecret() ;

    bool isEmpty();
};

// Contact::~Contact() {}

#endif