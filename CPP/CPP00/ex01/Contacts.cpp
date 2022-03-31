/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:21:41 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 14:37:49 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact()
{
	con_info[0] = std::string("First name");
	con_info[1] = std::string("Last name");
	con_info[2] = std::string("Nickname");
	con_info[3] = std::string("Phone number");
	con_info[4] = std::string("Darkest secret");
}

Contact::~Contact()
{}

void Contact::add_info()
{
	std::string str;
	int i;

	i = 0;
	str.clear();
	std::cout << "Fill in all the forms to create a new contact!" << std::endl;
	while (i < 5)
	{
		while (str.size() == 0)
		{
			std::cout << con_info[i] << std::endl;
			std::getline(std::cin, str);
			if (str.size() == 0)
				std::cout << "You have to fill in the argument!" << std::endl;
		}
		con_info[i] = str;
		str.clear();
		i++;
	}
}

std::string Contact::getInfos(int nb)
{
	return (con_info[nb]);
}