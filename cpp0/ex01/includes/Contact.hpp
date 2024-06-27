/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:56:56 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 14:41:30 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include <iomanip>
#include <sstream>

class Contact
{
public:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	long long	PhoneNumber;
	std::string	DarkestSecret;
	int	is_empty_field(std::string field);
	void	add_new_contact();
	void	format(std::string str);
	std::string	to_string(int n);
	void	print_basic(int n);
	void	print_full(void);
};

# endif