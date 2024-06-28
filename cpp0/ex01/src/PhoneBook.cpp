/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:40 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 17:45:18 by arturo           ###   ########.fr       */
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
	std::cout<<"\nEnter "<<field<<":\n";
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

void	pause()
{
	std::string enter;
	std::cout<<"(Press enter to continue)\n";
	std::getline(std::cin, enter);
}

void	PhoneBook::addContact()
{
	if (next > 7)
	{
		next = 7;
		for (int i = 0; i < 7; i++)
			contactList[i] = contactList[i + 1];
	}
	addField("first name", &Contact::setFirstName);
	addField("last name", &Contact::setLastName);
	addField("nickname", &Contact::setNickname);
	addField("phone number", &Contact::setPhoneNumber);
	addField("darkest secret", &Contact::setDarkestSecret);
	std::cout<<"\nNew contact succesfully added! ";
	pause();
	next++;
}

void	PhoneBook::search()
{
	int	index(-1);
	
	if (next == 0)
	{
		std::cout<<"No contacts saved. ";
		pause();
		return ;
	}
	while (true)
	{
		printShort("Index", '|');
		printShort("First name", '|');
		printShort("Last name", '|');
		printShort("Nickname", '\n');
		for (int i = 0; i < next; i++)
			contactList[i].displayShort(i);
		std::cout<<"Select index of contact for more information, or enter 0 to go back to the main menu\n";
		std::cin>>index;
		if (std::cin.fail())
		{
			std::cin.clear(); // Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input line
			std::cout<<"Invalid index\n";
			pause();
			continue ;
		}
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input line
		if (index > next || index < 0)
		{
			std::cout<<"Invalid index.";
			pause();
			continue ;
		}
		if (index == 0)
			return ;
		contactList[index - 1].displayLong();
		pause();
	}
}