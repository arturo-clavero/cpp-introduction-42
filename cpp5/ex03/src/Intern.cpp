/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 02:23:45 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 02:44:57 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

Intern::Intern(){
	std::cout<<"Constructor for intern called\n";
}

Intern::Intern(Intern const &og){
	(void)og;
	std::cout<<"Copy constructor for intern called\n";
}

Intern	&Intern::operator=(Intern const &og){
	(void)og;
	std::cout<<"Copy assignment operator for intern called\n";
	return *this;
}

Intern::~Intern(){
	std::cout<<"Destructor for intern called\n";
}

AForm	*Intern::makeRobot(std::string const target) const{
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm	*Intern::makeShrub(std::string const target) const{
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

AForm	*Intern::makePresi(std::string const target) const{
	AForm *form = new PresidentialPardonForm(target);
	return form;
}
	
AForm	*Intern::makeForm(std::string const name, std::string const target) const{
	AForm	*form = NULL;
	AForm *(Intern::*functions[])(std::string const) const = {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePresi};
	std::string	arrayLevels[3] = {"shrubbery request", "robotomy request", "presidential request"};
	for (int i = 0; i < 3; i++)
	{
		if (name == arrayLevels[i])
		{
			form = (this->*functions[i])(target);
			std::cout<<"Intern creates form "<<name<<" with target "<<target<<"\n";
			return form;
		}
	}
	std::cout<<"Form "<<name<<" is invalid, please use 'shrubbery request', 'robotomy request' or 'presidential request' instead\n";
	return form;
}
