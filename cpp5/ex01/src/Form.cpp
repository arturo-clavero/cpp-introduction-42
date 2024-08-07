/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:37:42 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 21:31:12 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


//ORTHODOX:
Form::Form(std::string const &name, const int sign, const int exec): _name(name),
																	_is_signed(false),
																	_required_grade_sign(sign),
																	_required_grade_execute(exec)
{
	if (_required_grade_execute < 1 || _required_grade_sign < 1)
		throw GradeTooHighException();
	if (_required_grade_execute > 150 || _required_grade_sign > 150)
		throw GradeTooLowException();
	std::cout<<"Constructor called for: "<<*this;
}

Form::Form(Form const &og) : _name(og.getName()),
							_is_signed(false),
							_required_grade_sign(og.getRequiredGradeSign()),
							_required_grade_execute(og.getRequiredGradeExecute())
{
	std::cout<<"Copy constructor called for: "<<*this;
}

Form	&Form::operator=(Form const &og){
	_is_signed = og.getIsSigned();
	std::cout<<"Copy assignment operator called for: "<<*this;
	return *this;
}

Form::~Form(){
	std::cout<<"Destructor called for: "<<*this;
}

//GETTERS:

std::string	Form::getName() const{
	return _name;
}

bool		Form::getIsSigned() const{
	return _is_signed;
}

int			Form::getRequiredGradeSign() const{
	return _required_grade_sign;
}

int			Form::getRequiredGradeExecute() const{
	return _required_grade_execute;
}


//OTHER
void		Form::beSigned(Bureaucrat const & bur){
	if (bur.getGrade() > _required_grade_sign)
	{
		bur.signForm(*this);
		throw GradeTooLowException();
	}
	_is_signed = true;
	bur.signForm(*this);
}

//PRINT

std::ostream	&operator<<(std::ostream &out, Form const &form){
	out<<"Form "<<form.getName()<<", ";
	if (form.getIsSigned() == true)
		out<<"(signed), ";
	else
		out<<"(NOT signed), ";
	out<<"required grade for signing ["<<form.getRequiredGradeSign()<<"] and for executing ["<<form.getRequiredGradeExecute()<<"]\n";
	return out;
}