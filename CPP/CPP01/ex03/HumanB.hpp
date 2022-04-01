/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:10:28 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/01 13:52:36 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	
public:
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};