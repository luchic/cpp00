/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookInterface.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:21:49 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/14 17:00:00 by nluchini         ###   ########.fr       */
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
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEnd of input detected. Exiting." << std::endl;
			break;
		}
		if (command == "ADD") {
			_handleAddCommand();
		} else if (command == "SEARCH") {
			_handleSearchCommand();
		} else if (command == "EXIT") {
			std::cout << "Exiting PhoneBook." << std::endl;
			break;
		} else {
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
	std::string name;
	std::string last_name;

	name = _getStringInput("Enter First Name: ");
	last_name = _getStringInput("Enter Last Name: ");
	auto contact = _phoneBook.getContactByName(name, last_name);
	if (contact.has_value())
		_displayContact(contact.value());
	else
		std::cout << "Contact not found." << std::endl;
}

std::string PhoneBookInterface::_getInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nEnd of input detected. Returning to main menu." << std::endl;
			return "";
		}
		if (input.empty()) {
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		}
		
	} while (input.empty());
	return input;
}

std::string PhoneBookInterface::_getStringInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nEnd of input detected. Returning to main menu." << std::endl;
			return "";
		}
		if (input.empty()) {
			std::cout << "Name cannot be empty. Please try again." << std::endl;
		} else if (!_isValidName(input)) {
			std::cout << "Name can only contain letters and spaces. Please try again." << std::endl;
			input = ""; // Reset to continue loop
		}
	} while (input.empty());
	return input;
}

std::string PhoneBookInterface::_getPhoneInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nEnd of input detected. Returning to main menu." << std::endl;
			return "";
		}
		if (input.empty()) {
			std::cout << "Phone number cannot be empty. Please try again." << std::endl;
		} else if (!_isValidPhone(input)) {
			std::cout << "Phone number can only contain digits, spaces, +, -, (, ). Please try again." << std::endl;
			input = ""; // Reset to continue loop
		}
	} while (input.empty());
	return input;
}

bool PhoneBookInterface::_isValidName(const std::string& name)
{
	for (char c : name) {
		if (!std::isalpha(c) && c != ' ' && c != '-' && c != '\'') {
			return false;
		}
	}
	return true;
}

bool PhoneBookInterface::_isValidPhone(const std::string& phone)
{
	for (char c : phone) {
		if (!std::isdigit(c) && c != ' ' && c != '-' && c != '+' && c != '(' && c != ')') {
			return false;
		}
	}
	return true;
}

void PhoneBookInterface::_displayValue(const std::string& value)
{
	if (value.length() > 10) {
		std::cout << value.substr(0, 8) << ".";
	} else {
		std::cout << value << std::setw(10 - value.length());
	}
}

void PhoneBookInterface::_displayContact(const Contact& contact)
{
	int index = _phoneBook.getIndex(contact);
	std::string name = contact.getFirstName();
	std::string last_name = contact.getLastName();
	std::string nickname = contact.getNickname();
	std::cout << "Contact found at index " << index << ":\n";
	std::cout << "| " << index << " |";
	_displayValue(name);
	std::cout << "|";
	_displayValue(last_name);
	std::cout << "|";
	_displayValue(nickname);
	std::cout << "|" << std::endl;
}