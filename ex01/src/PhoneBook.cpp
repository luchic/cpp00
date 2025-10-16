/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:23:46 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/15 19:04:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::optional<Contact> PhoneBook::getContactByIndex(int index) const
{
	if (index < 0 || index >= _size)
	{
		return std::nullopt;
	}
	return _contacts[index];
}

void PhoneBook::addContact(Contact contact)
{
	_contacts[_currentIndex % MAX_CONTACTS] = contact;
	_currentIndex = (_currentIndex + 1) % MAX_CONTACTS;
	if (_size < MAX_CONTACTS)
		_size++;
}

int PhoneBook::getSize() const
{
	return _size;
}