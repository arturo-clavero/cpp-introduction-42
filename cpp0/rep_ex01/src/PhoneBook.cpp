/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:40 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 15:47:38 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	std::cout<<"Default constructor for class 'Phonebook' called\n\n";
	next = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout<<"\nDestructor for class 'Phonebook' called\n";
}

void	PhoneBook::addField(std::string field, bool (Contact::*set)(std::string))
{
	std::string	str;
	std::cout<<"Enter "<<field<<":\n";
	std::getline(std::cin, str);
	while (!(contactList[next].*set)(str))
	{
		if (field != "phone number")
			std::cout<<"This field can not be empty, please enter "<<field<<"\n";
		else
			std::cout<<"Invalid phone number, please enter a 10 digit number (no spaces)\n";
		std::getline(std::cin, str);
	}
}

void	PhoneBook::addContact()
{
	if (next > 8)
	{
		next = 8;
		for (int i = 0; i < 7; i++)
			contactList[i] = contactList[i + 1];
	}
	addField("first name", &Contact::setFirstName);
	addField("last name", &Contact::setLastName);
	addField("nickname", &Contact::setNickname);
	addField("phone number", &Contact::setPhoneNumber);
	addField("darkest secret", &Contact::setDarkestSecret);
	std::cout<<"New contact succesfully added!\n\n";
	next++;
}

void	PhoneBook::search()
{
	std::cout<<"Unavailable feature\n";
}