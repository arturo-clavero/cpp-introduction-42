/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:53:37 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 14:53:05 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contact[8];
		bool	print_all(int n);
		void	print_index(int n);
		void	delete_old_contact(void);
};

#endif
