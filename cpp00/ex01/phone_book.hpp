#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <istream>
#include "contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook{
private:
    Contact contact[3];
    int     index;
	int		totalContact;
public:
	PhoneBook();
	// ~PhoneBook();

	void addContact(Contact newContact); 
	void displayContact();
	void displayContactDetails(int index);
	void searchContacts(PhoneBook& phoneBook);
	int getTotalContact();

};

#endif