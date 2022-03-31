/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:58:08 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 18:40:35 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void setName(std::string name);

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif