/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:53:37 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 14:08:31 by arturo           ###   ########.fr       */
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

class Phonebook
{
public:
	Contact contact[8];
	bool	print_all(int n)
	{
		if (n < 0)
		{
			std::cout<<"No contacts\n\n";
			return (false);
		}
		contact[0].format("Index");
		contact[0].format("First Name");
		contact[0].format("Last Name");
		contact[0].format("Nickname");
		std::cout<<"\n";
		for (int i = 0; i <= n; i++)
			contact[i].print_basic(i);
		return (true);
	}
	void	print_index(int n)
	{
		contact[n].print_full();
	}
	void	delete_old_contact(void)
	{
		for (int i = 0; i < 7; i++)
			contact[i] = contact[i + 1];
	}
};

#endif
