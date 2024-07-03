/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:11:26 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 05:29:35 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), Form("presidential request", 25, 5), name("Presidential Pardon"), target("default"), signGrade(25), execGrade(5){
	std::cout<<"Default constructor called for Presidential\n";
	isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), Form("presidential request", 25, 5), name("Presidential Pardon"), target("default"), signGrade(25), execGrade(5) {
	std::cout<<"Constructor called for Presidential with target "<<target<<"\n";
	isSigned = false;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) : AForm("Presidential Pardon", 25, 5), Form("presidential request", 25, 5), name("Presidential Pardon"), target("default"), signGrade(25), execGrade(5){
	std::cout<<"Copy constructor called for Presidential\n";
	isSigned = original.isSigned;
	target = original.target;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &original){
	std::cout<<"Copy assignment operator called for Presidential\n";
	isSigned = original.isSigned;
	target = original.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout<<"Destructor called for Presidential with target "<<target<<"\n";
}

void	PresidentialPardonForm::performTask() const{
	std::cout<<target<<" has been pardoned by Zaphod Beeblebrox\n";
}