/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:55:54 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 19:00:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form	*Intern::makeRobot(std::string target){
	Form *form = new RobotomyRequestForm(target);
	return form;
}

Form	*Intern::makeShrub(std::string target){
	Form *form = new ShrubberyCreationForm(target);
	return form;
}

Form	*Intern::makePresi(std::string target){
	Form *form = new PresidentialPardonForm(target);
	return form;
}
	
Form	*Intern::makeForm(std::string type, std::string target){
	Form	*form = NULL;
	Form *(Intern::*functions[])(std::string) = {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePresi};
	std::string	arrayLevels[3] = {"shrubbery request", "robotomy request", "presidential request"};
	for (int i = 0; i < 3; i++)
	{
		if (type == arrayLevels[i])
		{
			form = (this->*functions[i])(target);
			std::cout<<"Intern creates form "<<type<<" with target "<<target<<"\n";
			return form;
		}
	}
	std::cout<<"Form "<<type<<" is invalid, please use 'shrubbery request', 'robotomy request' or 'presidential request' instead\n";
	return form;
}

Intern::Intern(){
	std::cout<<"Default constructor called for class Intern\n";
}

Intern::Intern(const Intern &original){
	std::cout<<"Copy constructor called for class Intern\n";
	(void)original;
}

Intern	&Intern::operator=(const Intern &original){
	std::cout<<"Copy assignment operator called for class Intern\n";
	(void)original;
	return *this;
}

Intern::~Intern(){
	std::cout<<"Destructor called for class Intern\n";
}