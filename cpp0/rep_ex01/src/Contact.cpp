/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:43:06 by arturo            #+#    #+#             */
/*   Updated: 2024/06/28 17:43:13 by arturo           ###   ########.fr       */
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

void	printSpace(int n)
{
	for (int i = 0; i < n; i++)
		std::cout<<" ";
}

void	printShort(std::string str, char end)
{
	printSpace(10 - str.length());
	for (int i = 0; i < (int)str.length() && i < 9; i++)
		std::cout<<str[i];
	if (str.length() > 10)
		std::cout<<"."<<end;
	else if (str.length() == 10)
		std::cout<<str[9]<<end;
	else
		std::cout<<end;
}

void	Contact::displayShort(int index)
{
	printSpace(9);
	std::cout<<index + 1<<"|";
	printShort(firstName, '|');
	printShort(lastName, '|');
	printShort(nickname, '\n');
}

void	Contact::displayLong()
{
	std::cout<<"\nFirst name: "<<firstName<<"\n";
	std::cout<<"Last name: "<<lastName<<"\n";
	std::cout<<"Nickname: "<<nickname<<"\n";
	std::cout<<"Phone number: "<<phoneNumber<<"\n";
	std::cout<<"Darkest secret: "<<darkestSecret<<"\n\n";
}