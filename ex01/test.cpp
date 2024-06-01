/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:49:46 by arturo            #+#    #+#             */
/*   Updated: 2024/06/01 16:18:18 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

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
	void	print_basic(int n)
	{
		format(std::to_string(n));
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

int	main(void)
{
	Phonebook	UserPhonebook;
	Contact		UserContact;
	std::string	UserInput;
	int			n = -1;
	int			index;
	
	while (1)
	{
		std::cout<<"Please enter ADD, SEARCH or EXIT\n";
		std::cin>>UserInput;
		std::cin.ignore();
		if (UserInput == "ADD")
		{
			UserContact.add_new_contact();
			if (n >= 7)
			{
				UserPhonebook.delete_old_contact();
				n = 6;
			}
			UserPhonebook.contact[++n] = UserContact;
		}
		else if (UserInput == "SEARCH")
		{
			if (UserPhonebook.print_all(n))
			{
				while (1)
				{
					std::cout<<"Select contact index, or select 9 to go back\n";
					if (std::cin>>index && ((index <= n || index == 9) && index >= 0))
						break ;
					std::cin.clear();
					std::cin.ignore();
					std::cout<<"invalid index...\n\n";
				}
				if (index != 9)
					UserPhonebook.print_index(index);
				std::cout<<"\n";
			}
		}
		else if (UserInput == "EXIT")
			break ;
		else
			std::cout<<"Invalid input..\n\n";
	}
}
