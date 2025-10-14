/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:14:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/14 15:51:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookInterface.hpp"

int main()
{
	PhoneBook phoneBook;
	PhoneBookInterface interface(phoneBook);
	interface.run();
	return (0);
}