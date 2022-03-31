/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:58:08 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 18:27:05 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie(std::string name);
	~Zombie();

	void announce(void);

private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif