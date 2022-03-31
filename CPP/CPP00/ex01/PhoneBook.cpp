/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:42:37 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 16:03:17 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

phonebook::phonebook()
{
	nb = 0;
	oldest = 0;
}

phonebook::~phonebook()
{}

void phonebook::add()
{
	Contact tmp;
	if (nb > 7)
	{
		contact[oldest] = tmp;
		contact[oldest].add_info();
		oldest++;
	}
	else
	{
		contact[nb].add_info();
		nb++;
	}
}

void phonebook::search()
{
	int	i;
	int	j;
	int	index;
	Contact tmp;

	i = 0;
	// index = 0;
	j = 0;
	if (nb == 0)
		std::cout << "There are 0 contacts registered in your phonebook!" << std::endl;
	else
	{
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		while (i < nb)
		{
			j = 0;
			std::cout << std::setw(10) << i + 1;
			while (j < 3)
			{
				if (contact[i].getInfos(j).size() < 10)
					std::cout << std::setw(10) << contact[i].getInfos(j) << "|";
				else
					std::cout << contact[i].getInfos(j).substr(0, 9) << ".|";
				j++;
			}
			std::cout << std::endl;
			i++;
		}
		while (1)
		{
			std::cout << "Enter a valid contact index (1 to " << nb << ") or 0 to go back" << std::endl;
			std::cin >> index;
			if (index > nb || index < 0 || std::cin.fail())
			{
				std::cout << "Invalid index! Please enter a valid one!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				if (index != 0)
				{
					i = 0;
					std::cout << "Information for index: " << index << " -> " << std::endl;
					while (i < 5)
					{
						std::cout << tmp.getInfos(i) << ": " << contact[index - 1].getInfos(i) << std::endl;
						i++;
					}
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}
		}
	}
}
