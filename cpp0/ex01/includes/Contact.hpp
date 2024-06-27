/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:56:56 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 14:32:14 by arturo           ###   ########.fr       */
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
	int	is_empty_field(std::string field)
	{
		if (field.empty())
			return (true);
		for (int i = 0; field[i]; i++)
		{
			if (field[i] != ' ' && field[i] != '\t' && field[i] != '\n')
				return (false);
		}
		return (true);
	}
	void	add_new_contact()
	{
		while (true)
		{
			std::cout<<"Input first name\n";
			std::getline(std::cin, FirstName);
			if (!is_empty_field(FirstName))
				break ;
		}
		while (true)
		{
			std::cout<<"Input last name\n";
			std::getline(std::cin, LastName);
			if (!is_empty_field(LastName))
				break ;
		}
		while (true)
		{
			std::cout<<"Input nick-name\n";
			std::getline(std::cin, Nickname);
			if (!is_empty_field(Nickname))
				break ;
		}
		while (true)
		{
			std::cout<<"Input phone number\n";
			if (std::cin>>PhoneNumber)
				break;
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"That was not a phone number\n\n";
		}
		std::cin.ignore();
		while (true)
		{
			std::cout<<"Input darkest secret\n";
			std::getline(std::cin, DarkestSecret);
			if (!is_empty_field(DarkestSecret))
				break ;
		}
	}
	void	format(std::string str)
	{
		int	i;
		int	white_space = 10 - str.size();
		for (i = 0; i < white_space; i++)
			std::cout<<" ";
		for (i = 0; str[i] && i < 9; i++)
			std::cout<<str.at(i);
		if (str.size() > 10)
			std::cout<<".";
		else if (str.size() == 10)
			std::cout<<str.at(str.size() - 1);
		std::cout<<"|";
	}
	std::string	to_string(int n)
	{
		std::stringstream ss;
        ss << n;
        return ss.str();
	}
	void	print_basic(int n)
	{
		format(to_string(n));
		format(FirstName);
		format(LastName);
		format(Nickname);
		std::cout<<"\n";
	}
	void	print_full(void)
	{
		std::cout<<"First name: "<<FirstName<<"\n";
		std::cout<<"Last name: "<<LastName<<"\n";
		std::cout<<"Nickname: "<<Nickname<<"\n";
		std::cout<<"Phone number: "<<PhoneNumber<<"\n";
		std::cout<<"Darkest secret: "<<DarkestSecret<<"\n";
	}
};

# endif