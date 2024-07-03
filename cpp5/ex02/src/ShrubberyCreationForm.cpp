/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:35 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 18:39:10 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 37), name("Shrubbery Creation Form"), target("default"), signGrade(145), execGrade(37){
	std::cout<<"Default constructor called for Shrubbery\n";
	isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 37), name("Shrubbery Creation Form"), target("default"), signGrade(145), execGrade(37) {
	std::cout<<"Constructor called for Shrubbery with target "<<target<<"\n";
	isSigned = false;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm("Shrubbery Creation Form", 145, 37), name("Shrubbery Creation Form"), target("default"), signGrade(145), execGrade(37){
	std::cout<<"Copy constructor called for Shrubbery\n";
	isSigned = original.isSigned;
	target = original.target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original){
	std::cout<<"Copy assignment operator called for Shrubbery\n";
	isSigned = original.isSigned;
	target = original.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout<<"Destructor called for Shrubbery with target "<<target<<"\n";
}

void	ShrubberyCreationForm::performTask() const{
	std::cout<<"Performing shurbbb task\n";
}
/*
There is a Makefile that compiles using the appropriate flags
There are concrete forms that are conform to the specifications of the
subject (required grades, names and actions).
They take only one parameter in their constructor, which is their target.
There is a Form::execute(Bureaucrat const & executor) method that works
as specified by the subject.
Either this method is pure and the grade checks are implemented in each
subclass, or this method performs the checks, then calls another method
in derived class that only executes the action.
Both of these techniques are valid.
There is a Bureaucrat::executeForm(Form const & form) that works as
specified by the subject.
*/