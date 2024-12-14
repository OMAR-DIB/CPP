#include "phone_book.hpp"
#include <iostream>
#include <string>
using std::string;

bool isValidPhoneNumber(const std::string& phoneNb) {
	if (phoneNb.empty()) {
		std::cout << "Validation failed: The input string is empty.\n";
		return false;
	}
	for (char c : phoneNb) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

// Function to check for empty value or substring "nb"
bool validateString(const std::string& input) {
	if (input.empty()) {
		std::cout << "Validation failed: The input string is empty.\n";
		return false;
	}
	for (char c:input)
	{
	if (!isalpha(c)) {
		std::cout << "Validation failed: The input string contains 'nb'.\n";
		return false;
	}
	}

	std::cout << "Validation passed: The input string is valid.\n";
	return true;
}

void add(PhoneBook& phoneBook) {
	Contact contact;
	string input;

	while (true)
	{
		/* code */
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (validateString(input)) {
		
	contact.setFirstName(input);
		break;
	}else{
		std::cout << "Invalid first name! Please try again.\n";
	}
	}
	

	while (true)
	{
		/* code */
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (validateString(input)) {
	contact.setLastName(input);
		break;;
	}else{
		std::cout << "Invalid last name! Please try again.\n";

	}
	}
	
	while (true)
	{
		/* code */
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (validateString(input)) {
	contact.setNickname(input);
		break;
	}else{
		std::cout << "Invalid nickname! Please try again.\n";

	}
	}
	

	while (true) {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);

		if (isValidPhoneNumber(input)) {
			contact.setPhoneNb(input);
			break;
		} else {
			std::cout << "Invalid phone number! Please enter only digits.\n";
		}
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.setSecret(input);

	if (contact.isEmpty()) {
		std::cout << "All fields must be complete.\n";
	} else {
		phoneBook.addContact(contact);
		std::cout << "Contact added successfully.\n";
	}
}


void searchContacts(PhoneBook& phoneBook) {
	if (phoneBook.getTotalContact() == 0) {  // Check if the phone book is empty
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

int main() {
	PhoneBook phoneBook;
	string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			add(phoneBook);
		} else if (command == "SEARCH") {
			searchContacts(phoneBook);
		} else if (command == "EXIT") {
			std::cout << "Exiting program.\n";
			break;
		} else {
			std::cout << "Invalid command.\n";
		}
	}

	return 0;
}
