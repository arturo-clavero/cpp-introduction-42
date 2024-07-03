/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:29:11 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 05:58:26 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), signGrade(1), execGrade(1){
	std::cout<<"Form default constructor called\n";
	isSigned = false;
}

Form::Form(const std::string name_param, int signGrade, int execGrade) : name(name_param), signGrade(signGrade), execGrade(execGrade) {
	std::cout<<"Constructor with paremeters called for form "<<name<<"\n";
	if (execGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150)
		throw GradeTooLowException();
	isSigned = false;
}

Form::Form(Form const &original) : name(original.name), signGrade(original.signGrade), execGrade(original.execGrade){
	std::cout<<"Form copy constructor called\n";
	isSigned = original.isSigned;
}

Form	&Form::operator=(Form const &original) {
	std::cout<<"Form copy assignment operator called\n";
	isSigned = original.isSigned;
	return *this;
}

Form::~Form(){
	std::cout<<"Destructor called for form\n";
}

std::string	Form::getName(){
	return name;
}

int	Form::getSignGrade(){
	return signGrade;
}

int	Form::getExecGrade(){
	return execGrade;
}

int	Form::getIsSigned() {
	return isSigned;
}

void	Form::beSigned(Bureaucrat &bur) {
	std::cout<<"Bureaucrat "<<bur.getName()<<" with grade "<<bur.getGrade()<<" wants to sign form "<<name<<"\n";
	if (bur.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;	
	std::cout<<"Form "<<name<<" was signed by "<<bur.getName()<<"\n";
}

void	Form::signForm(Bureaucrat &bur) {
	if (isSigned)
		std::cout<<"Bureaucrat "<<bur.getName()<<" signed form "<<name<<std::endl;
	else if (bur.getGrade() > signGrade)
		std::cout<<"Bureaucrat "<<bur.getName()<<" couldn't sign form "<<name<<" because their grade is too low\n";
	else
		std::cout<<"Bureaucrat "<<bur.getName()<<" couldn't sign form "<<name<<" because they are incompetent\n";
}

std::ostream	&operator<<(std::ostream &cout_param, Form &form){
	std::cout<<form.getName()<<", signed: "<<form.getIsSigned()<< ", required grade for signing: "<<form.getSignGrade()<<", required grade for executing: "<<form.getExecGrade()<<std::endl;
	return (cout_param);
};