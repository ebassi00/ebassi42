/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:57:35 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/01 15:07:28 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void replace(char *argv[])
{
	int	i;
	std::string filename;
	std::string s1(argv[1]);
	std::string s2(argv[2]);
	std::string tmp;
	std::fstream file;

	file.open(argv[0], std::fstream::in);
	filename = argv[0];
	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i] == '.')
			break;
		i++;
	}
	filename = filename.substr(0, i) + ".replace";
	std::ofstream output(filename, std::fstream::out);
	while (std::getline(file, tmp))
	{
		while (true)
		{
			size_t found;
			found = tmp.find(s1);
			if (found != std::string::npos)
			{
				tmp.erase(found, s1.length());
				tmp.insert(found, s2);
			}
			else
				break;
		}
		output << tmp;
	}
	output.close();
	file.close();
}

int main (int argc, char *argv[])
{
	if (argc == 4)
		replace(&argv[1]);
	return (0);
}