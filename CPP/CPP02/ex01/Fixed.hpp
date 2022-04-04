/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:08:47 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/04 14:34:50 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr_float);
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _rawBits;
	static const int _bit = 8;
};

#endif