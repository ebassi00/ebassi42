/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:13:25 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 15:34:36 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iomanip>
#include "Contacts.hpp"

class phonebook {

	public:
		phonebook();
		~phonebook();

		void add();
		void search();
	
	private:
		Contact contact[8];
		int nb;
		int	oldest;
};

#endif