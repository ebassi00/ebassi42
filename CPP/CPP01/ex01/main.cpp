/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:13:49 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 18:42:07 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int count = 42;
	Zombie *horde = zombieHorde(count, "erdio");

	horde->announce();
	for (int i = 0; i < count; i++)
		horde[i].announce();
	delete [] horde;
}