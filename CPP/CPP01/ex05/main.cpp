/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:21 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/01 15:33:07 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

int main()
{
	Karen karen;

	std::cout << "[ DEBUG ]" << std::endl;
	karen.complain("DEBUG");
	std::cout << "[ INFO ]" << std::endl;
	karen.complain("INFO");
	std::cout << "[ WARNING ]" << std::endl;
	karen.complain("WARNING");
	std::cout << "[ ERROR ]" << std::endl;
	karen.complain("ERROR");
}