/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:47:39 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/31 14:11:13 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_CLASS_HPP
# define CONTACTS_CLASS_HPP

# include <iostream>

class Contact {

	public:
		Contact(void);
		~Contact(void);

		void add_info();
		std::string getInfos(int nb);
	
	private:
		std::string con_info[5];
};

#endif