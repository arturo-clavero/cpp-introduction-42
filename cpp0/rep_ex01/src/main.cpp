/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:51:55 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 17:26:16 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	myPhoneBook;
	std::string	userPrompt("");

	while (userPrompt != "EXIT")
	{
		std::cout<<"\nThis is a phonebook, please enter one of these three commands: \nADD, SEARCH or EXIT\n";
		std::getline(std::cin, userPrompt);
		if (userPrompt == "ADD")
			myPhoneBook.addContact();
		else if (userPrompt == "SEARCH")
			myPhoneBook.search();
		else if (userPrompt != "EXIT")
		{
			std::cout<<"Invalid prompt. ";
			pause();
		}
	}
	return (0);
}