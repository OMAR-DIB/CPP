 
#include "phone_book.hpp"

PhoneBook::PhoneBook() : index(0)  , totalContact(0) {}


void PhoneBook::addContact(Contact newContact){
    contact[index] = newContact;
    index = (index + 1) % 3;
    if (totalContact < 3)
    {
        totalContact++;
    }
}

int PhoneBook::getTotalContact()
{
    return totalContact;
}

void PhoneBook::displayContact()
{
    std::cout << std::setw(6) << "Index"
			  << " | " << std::setw(11) << "First Name"
			  << " | " << std::setw(11) << "Last Name"
			  << " | " << std::setw(11) << "Nick Name"
			  << std::endl;
    
    for (int i = 0; i < this->totalContact; i++) {
        std::cout << std::setw(6) << i
				  << " | " << std::setw(11) << this->contact[i].getFirstName()
				  << " | " << std::setw(11) << this->contact[i].getLastName()
				  << " | " << std::setw(11) << this->contact[i].getNickname()
				  << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::displayContactDetails(int index) {
    if (index >= 0 && index < totalContact) {
        Contact& cont = contact[index];
        std::cout << "First Name: " << cont.getFirstName() << "\n";
        std::cout << "Last Name: " << cont.getLastName() << "\n";
        std::cout << "Nickname: " << cont.getNickname() << "\n";
        std::cout << "Phone Number: " << cont.getPhoneNb() << "\n";
        std::cout << "Darkest Secret: " << cont.getSecret() << "\n";
    } else {
        std::cout << "Invalid index!\n";
    }
}

void PhoneBook::searchContacts(PhoneBook& phoneBook) {
    if (totalContact == 0) {  // Check if the phone book is empty
        std::cout << "PhoneBook is empty. No contacts to display.\n";
        return;
    }
    phoneBook.displayContact();

    std::cout << "Enter the index of the contact you want to view: ";
    string indexInput;
    std::getline(std::cin, indexInput);

    try {
        int index = std::stoi(indexInput);
        phoneBook.displayContactDetails(index);
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid index input!\n";
    }
}
