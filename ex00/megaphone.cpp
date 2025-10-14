/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:05:50 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/12 13:44:04 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void to_toupper(std::string::iterator it, std::string::iterator end)
{
	for (; it != end; it++)
		*it = std::toupper(*it);
}

int main(int argc, char **argv)
{
	std::string str;
	if (argc == 1)
		return 0;
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		to_toupper(str.begin(), str.end());
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return 0;
}