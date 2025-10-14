/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookInterface.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:14:11 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/14 16:56:30 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include "PhoneBook.hpp"

class PhoneBookInterface {
private:
    PhoneBook& _phoneBook;
	
	void _displayValue(const std::string& value);
    void _displayContact(const Contact& contact);
	void _handleAddCommand();
    void _handleSearchCommand();
	// void _displayContacts();
	std::string _getInput(const std::string& prompt);
	std::string _getStringInput(const std::string& prompt);
	std::string _getPhoneInput(const std::string& prompt);
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