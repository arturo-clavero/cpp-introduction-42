/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:43:06 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 15:04:07 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	std::cout<<"Default constructor for class 'Contact' called\n";
}

Contact::~Contact(){
	std::cout<<"Destructor for class 'Contact' called\n";
}

bool	stringOnlySpaces(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			return false;
	}
	return true;
}

bool	Contact::setFirstName(std::string firstName) {
	if (stringOnlySpaces(firstName))
		return false;
	this->firstName = firstName;
	return true;
}

bool	Contact::setLastName(std::string lastName) {
	if (stringOnlySpaces(lastName))
		return false;
	this->lastName = lastName;
	return true;
}

bool	Contact::setNickname(std::string nickname) {
	if (stringOnlySpaces(nickname))
		return false;
	this->nickname = nickname;
	return true;
}

bool	Contact::setPhoneNumber(std::string phoneNumber) {
	if (phoneNumber.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		char	c = phoneNumber[i];
		if (c < '0' || c > '9')
			return false;
	}
	this->phoneNumber = phoneNumber;
	return true;
}

bool	Contact::setDarkestSecret(std::string darkestSecret) {
	if (stringOnlySpaces(darkestSecret))
		return false;
	this->darkestSecret = darkestSecret;
	return true;
}