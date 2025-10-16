/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookInterface.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:21:49 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/15 18:41:51 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookInterface.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBookInterface::PhoneBookInterface(PhoneBook& pb) : _phoneBook(pb) {}

void PhoneBookInterface::setPhoneBook(PhoneBook& pb)
{
	_phoneBook = pb;
}

void PhoneBookInterface::run()
{
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEnd of input detected. Exiting." << std::endl;
			break;
		}
		if (command == "ADD")
		{
			_handleAddCommand();
		}
		else if (command == "SEARCH")
		{
			_handleSearchCommand();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook." << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
}

void PhoneBookInterface::_handleAddCommand()
{
	Contact newContact;
	std::string value;

	value = _getStringInput("Enter First Name: ");
	newContact.setFirstName(value);
	value = _getStringInput("Enter Last Name: ");
	newContact.setLastName(value);
	value = _getStringInput("Enter Nickname: ");
	newContact.setNickname(value);
	value = _getPhoneInput("Enter Phone Number: ");
	newContact.setPhoneNumber(value);
	value = _getStringInput("Enter Darkest Secret: ");
	newContact.setDarkestSecret(value);
	_phoneBook.addContact(newContact);
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBookInterface::_handleSearchCommand()
{
	_displayAllContacts();
	
	if (_phoneBook.getSize() == 0)
	{
		std::cout << "No contacts available to search." << std::endl;
		return;
	}
	int index = _getIntInput("Enter the index of the contact to view details: ");
	auto contact = _phoneBook.getContactByIndex(index);
	if (contact.has_value())
	{
		std::cout << "Contact found:" << std::endl;
		std::cout << "First Name: " << contact->getFirstName() << std::endl;
		std::cout << "Last Name: " << contact->getLastName() << std::endl;
		std::cout << "Nickname: " << contact->getNickname() << std::endl;
		std::cout << "Phone Number: " << contact->getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact->getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Contact not found." << std::endl;
}

std::string PhoneBookInterface::_getInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			return "";
		}
		if (input.empty()) {
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		}
		
	} while (input.empty());
	return input;
}

int PhoneBookInterface::_getIntInput(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			return -1;
		}
		if (input.empty())
		{
			std::cout << "Index value cannot be empty. Please try again." << std::endl;
		} else if (!_isValidInt(input))
		{
			std::cout << "Index value must be a valid integer. Please try again." << std::endl;
			input = "";
		}
	} while (input.empty());
	return std::stoi(input);
}

std::string PhoneBookInterface::_getStringInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			return "";
		}
		if (input.empty())
		{
			std::cout << "Name cannot be empty. Please try again." << std::endl;
		} else if (!_isValidName(input))
		{
			std::cout << "Name can only contain letters and spaces. Please try again." << std::endl;
			input = "";
		}
	} while (input.empty());
	return input;
}

std::string PhoneBookInterface::_getPhoneInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			return "";
		}
		if (input.empty())
		{
			std::cout << "Phone number cannot be empty. Please try again." << std::endl;
		}
		else if (!_isValidPhone(input))
		{
			std::cout << "Phone number can only contain digits, spaces, +, -, (, ). Please try again." << std::endl;
			input = "";
		}
	} while (input.empty());
	return input;
}

bool PhoneBookInterface::_isValidName(const std::string& name)
{
	for (char c : name) {
		if (!std::isalpha(c) && c != ' ' && c != '-' && c != '\'')
		{
			return false;
		}
	}
	return true;
}

bool PhoneBookInterface::_isValidPhone(const std::string& phone)
{
	for (char c : phone) {
		if (!std::isdigit(c) && c != ' ' && c != '-'
			&& c != '+' && c != '(' && c != ')')
		{
			return false;
		}
	}
	return true;
}

bool PhoneBookInterface::_isValidInt(const std::string& input)
{
	for (char c : input) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

void PhoneBookInterface::_displayValue(const std::string& value)
{
	if (value.length() > 10)
	{
		std::cout << value.substr(0, 8) << ".";
	}
	else
	{
		std::cout << std::setw(10) << value;
	}
}

void PhoneBookInterface::_displayContact(int index, const Contact& contact)
{
	std::string name = contact.getFirstName();
	std::string last_name = contact.getLastName();
	std::string nickname = contact.getNickname();
	
	std::cout << "|" << std::setw(10) << index << "|";
	_displayValue(name);
	std::cout << "|";
	_displayValue(last_name);
	std::cout << "|";
	_displayValue(nickname);
	std::cout << "|" << std::endl;
}

void PhoneBookInterface::_displayAllContacts()
{
	std::cout << "┌----------┬----------┬----------┬----------┐\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|----------┼----------┼----------┼----------|\n";
	for (int i = 0; i < _phoneBook.getSize(); i++) {
		auto cnt = _phoneBook.getContactByIndex(i);
		if (!cnt.has_value())
			break;
		_displayContact(i, cnt.value());
	}
	std::cout << "└----------┴----------┴----------┴----------┘" << std::endl; 
}