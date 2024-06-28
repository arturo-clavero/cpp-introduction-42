/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:37 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 15:36:06 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
/*
• PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. 

anything that will always be used inside a class is private, 
anything that can be used outside a class is public.


*/
#include "Contact.hpp"

class	PhoneBook{
	private:
		Contact	contactList[8];
		int		next;
		void	addField(std::string field, bool (Contact::*set)(std::string));
	
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	search();
};

#endif