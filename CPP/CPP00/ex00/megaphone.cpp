/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:05:16 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 12:40:36 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	char_capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = -1;
			while (argv[i][++j])
				std::cout << char_capitalize(argv[i][j]);
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}