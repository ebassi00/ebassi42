/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:17:39 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 16:14:05 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contacts.hpp"

int main()
{
	std::string command;
	phonebook phonebook;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			std::cout << "Closing Phonebook...everything is being deleted" << std::endl;
			break;
		}
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}