/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:49:46 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 14:55:42 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	UserPhonebook;
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
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
