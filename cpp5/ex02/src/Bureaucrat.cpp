/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:00:42 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 18:50:03 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){
	std::cout<<"Default constructor called\n";
};
		
Bureaucrat::Bureaucrat(const std::string name_param, int grade) : name(name_param)
{
	std::cout<<"Constructor with grade "<<grade<<" called for Bureaucrat '"<<name<<"'\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &original) : name(original.name){
	std::cout<<"Copy constructor called\n";
	grade = original.grade;		
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &original) {
	std::cout<<"Copy assignment operator called\n";
	grade = original.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout<<"Destructor called for bureaucrat "<<name<<std::endl;
}
		
std::string	Bureaucrat::getName(){
	return name;
}

int	Bureaucrat::getGrade() const{
	return grade;
}

void	Bureaucrat::increaseGrade(int amount){
	std::cout<<"Increasing grade by "<<amount<<std::endl;
	if (grade - amount < 1)
		throw GradeTooHighException();
	grade -= amount;
}

void	Bureaucrat::decreaseGrade(int amount){
	std::cout<<"Decreasing grade by "<<amount<<std::endl;
	if (grade + amount > 150)
		throw GradeTooLowException();
	grade += amount;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
}

std::ostream	&operator<<(std::ostream &cout_param, Bureaucrat &bur){
	std::cout<<bur.getName()<<", bureaucrat grade "<<bur.getGrade()<<std::endl;
	return (cout_param);
};
