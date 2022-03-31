/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:51:45 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 19:19:21 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

public:
	Weapon(std::string type);
	~Weapon();

	std::string const &getType() const;
	void setType(std::string type);

private:
	std::string _type;
};

#endif