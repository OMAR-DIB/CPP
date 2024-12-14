#include "contact.hpp"

Contact::Contact() : firstName(""), phoneNb(""), secret("") {}

void Contact::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(string lastName) 
{
     this->lastName = lastName;
}

void Contact::setNickname(string nickname) 
{ 
    this->nickname = nickname; 
}

void Contact::setPhoneNb(string phoneNb)
{
    this->phoneNb = phoneNb;
}

void Contact::setSecret(string secret)
{
    this->secret = secret;
}

string Contact::getFirstName()
{
    return this->firstName;
}
string Contact::getLastName() 
{ 
    return this->lastName; 
}
string Contact::getNickname()
{
    return this->nickname;
}
string Contact::getPhoneNb()
{
    return this->phoneNb;
}
string Contact::getSecret()
{
    return this->secret;
}

bool Contact::isEmpty()
{
    return firstName.empty() && lastName.empty() && nickname.empty() && phoneNb.empty() && secret.empty();
} 
