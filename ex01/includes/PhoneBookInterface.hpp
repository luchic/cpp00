/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookInterface.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:14:11 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/17 21:34:48 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOKINTERFACE_H__
#define __PHONEBOOKINTERFACE_H__

#include "PhoneBook.hpp"

class PhoneBookInterface {
private:
    PhoneBook& _phoneBook;
	
	void _displayValue(const std::string& value);
    void _displayContact(int index, const Contact& contact);
	void _displayAllContacts();
	void _handleAddCommand();
    void _handleSearchCommand();
	std::string _getInput(const std::string& prompt);
	int _getIntInput(const std::string& prompt);
	std::string _getStringInput(const std::string& prompt);
	std::string _getPhoneInput(const std::string& prompt);
	bool _isValidInt(const std::string& input);
	bool _isValidName(const std::string& name);
	bool _isValidPhone(const std::string& phone);

public:
	PhoneBookInterface() = delete;
    PhoneBookInterface(PhoneBook& pb);
	~PhoneBookInterface() {}

    void run();
    void setPhoneBook(PhoneBook& pb);
};

#endif