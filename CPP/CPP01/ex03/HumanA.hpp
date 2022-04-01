/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:01:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/01 13:54:00 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack();

private:
	std::string _name;
	Weapon &_weapon;
};