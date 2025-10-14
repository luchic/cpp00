/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:14:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/14 16:21:54 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"
#include <optional>

class PhoneBook
{
private:
	Contact _contacts[8];
	int _currentIndex;
	
	void setNewContact();
	
public:
	PhoneBook() = default;
	~PhoneBook();
	
	const Contact& getContacts(int index) const;
	const Contact* getAllContacts() const;
	std::optional<Contact> getContactByName(std::string name, std::string last_name);
	const Contact& getContactBySurname(std::string name) const;
	const Contact& getContactsByLastName(std::string last_name) const;
	int getIndex(Contact contact);
	void addContact(Contact contact);
};

#endif