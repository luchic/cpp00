/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:23:46 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/14 17:02:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook() {}
const Contact& PhoneBook::getContacts(int index) const
{
	// if (index < 0 || index >= 8) {
	// 	throw std::out_of_range("Index out of range");
	// }
	return _contacts[index];
}

std::optional<Contact> PhoneBook::getContactByName(std::string name, std::string last_name)
{
	for (int i = 0; i < _currentIndex; i++) {
		if (_contacts[i].getFirstName() == name && _contacts[i].getLastName() == last_name) {
			return _contacts[i];
		}
	}
	return std::nullopt;
}

void PhoneBook::addContact(Contact contact)
{
	_contacts[_currentIndex % 8] = contact;
	if (_currentIndex < 8)
		_currentIndex++;
}

int PhoneBook::getIndex(Contact contact)
{
	for (int i = 0; i < _currentIndex; i++) {
		if (_contacts[i] == contact) {
			return i;
		}
	}
	return -1; // Contact not found
}