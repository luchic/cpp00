/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:14:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/15 19:07:35 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"
#include <optional>

class PhoneBook
{
private:
	const static int MAX_CONTACTS = 8;
	Contact _contacts[MAX_CONTACTS];
	int _currentIndex;
	int _size;
	
public:
	PhoneBook() : _currentIndex(0), _size(0) {};
	~PhoneBook() = default;
	
	int getSize() const;
	int getMaxContacts() const { return MAX_CONTACTS; }
	std::optional<Contact> getContactByIndex(int index) const;
	void addContact(Contact contact);
};

#endif