/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:49:01 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 19:06:57 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signGrade(1), execGrade(1){
	std::cout<<"AForm default constructor called\n";
	isSigned = false;
}

AForm::AForm(const std::string name_param, int signGrade_param, int execGrade_param) : name(name_param), signGrade(signGrade_param), execGrade(execGrade_param){
	std::cout<<"Constructor with paremeters called for aform ('"<<name<<"')\n";
	if (execGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150)
		throw GradeTooLowException();
	isSigned = false;
}

AForm::AForm(AForm const &original) : name(original.name), signGrade(original.signGrade), execGrade(original.execGrade){
	std::cout<<"AForm copy constructor called\n";
	isSigned = original.isSigned;
}

AForm	&AForm::operator=(AForm const &original) {
	std::cout<<"AForm copy assignment operator called\n";
	return *this;
	isSigned = original.isSigned;
}

AForm::~AForm(){
	std::cout<<"Destructor called for aform "<<name<<std::endl;
}

std::string	AForm::getName(){
	return name;
}

int	AForm::getSignGrade(){
	return signGrade;
}

int	AForm::getExecGrade() const{
	return execGrade;
}

int	AForm::getIsSigned() {
	return isSigned;
}

void	AForm::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;	
}

void	AForm::signForm(Bureaucrat &bur) {
	if (isSigned)
		std::cout<<bur.getName()<<" signed "<<name<<std::endl;
	else if (bur.getGrade() > signGrade)
		std::cout<<bur.getName()<<" couldn't sign "<<name<<" because their grade is too low\n";
	else
		std::cout<<bur.getName()<<" couldn't sign "<<name<<" because they are incompetent\n";
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (isSigned && executor.getGrade() <= getExecGrade())
		performTask();
	else
		std::cout<<"Could not execute\n";
}

std::ostream	&operator<<(std::ostream &cout_param, AForm &form){
	std::cout<<form.getName()<<", signed: "<<form.getIsSigned()<< ", required grade for signing: "<<form.getSignGrade()<<", required grade for executing: "<<form.getExecGrade()<<std::endl;
	return (cout_param);
};