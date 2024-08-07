/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:07:17 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 19:12:43 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw	GradeTooHighException();
	if (grade > 150)
		throw	GradeTooLowException();
	std::cout<<"Constructor called for: "<<*this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &og) : _name(og.getName()), _grade(og.getGrade()) {
	std::cout<<"Copy constructor called for: "<<*this<<"\n";
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &og){
	std::cout<<"Copy assignment operator called for: "<<*this;
	_grade = og.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout<<"Destructor called for: "<<*this;
}

std::string	Bureaucrat::getName() const{
	return (_name);
}

int	Bureaucrat::getGrade()	const{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int const amount){
	if (_grade - amount < 1)
		throw GradeTooHighException();
	_grade -= amount;
	std::cout<<_name<<" got promoted from grade "<<_grade + amount<<" to "<<_grade<<".\n";
}

void	Bureaucrat::decrementGrade(int const amount){
	if (_grade + amount > 150)
		throw GradeTooLowException();
	_grade += amount;
	std::cout<<_name<<" got demoted from grade "<<_grade - amount<<" to "<<_grade<<".\n";
}

std::ostream	&operator<<(std::ostream & out, Bureaucrat const &bur){
	out<<"Bureaucrat "<<bur.getName()<<", grade ("<<bur.getGrade()<<")\n";
	return out;
}