/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:35:01 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 18:57:43 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

/*first name, last name, nickname, phone number, and
darkest secret.*/
class	Contact{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		~Contact();
	//setters:
		bool	setFirstName(std::string firstName);
		bool	setLastName(std::string lastName);
		bool	setNickname(std::string nickname);
		bool	setPhoneNumber(std::string phoneNumber);
		bool	setDarkestSecret(std::string darkestSecret);
	//prints:
		void	displayShort(int index);
		void	displayLong();
};
void	printShort(std::string str, char end);

#endif