/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:13:49 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 18:27:49 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("Caracciolo");
	zombie.announce();

	randomChump("Umberto");

	Zombie *undead = newZombie("Poraccio");
	undead->announce();
	delete undead;

	return (0);
}