/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:21 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/01 15:35:02 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        Karen karen;
		std::cout << std::endl;

        karen.complain(std::string(argv[1]));
		std::cout << std::endl;
    }
    return 0;
}