/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:37:42 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 00:20:59 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


//ORTHODOX:
AForm::AForm(std::string const &name, const int sign, const int exec): _name(name),
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

AForm::AForm(AForm const &og) : _name(og.getName()),
							_is_signed(false),
							_required_grade_sign(og.getRequiredGradeSign()),
							_required_grade_execute(og.getRequiredGradeExecute())
{
	std::cout<<"Copy constructor called for: "<<*this;
}

AForm	&AForm::operator=(AForm const &og){
	_is_signed = og.getIsSigned();
	std::cout<<"Copy assignment operator called for: "<<*this;
	return *this;
}

AForm::~AForm(){
	std::cout<<"Destructor called for: "<<*this;
}

//GETTERS:

std::string	AForm::getName() const{
	return _name;
}

bool		AForm::getIsSigned() const{
	return _is_signed;
}

int			AForm::getRequiredGradeSign() const{
	return _required_grade_sign;
}

int			AForm::getRequiredGradeExecute() const{
	return _required_grade_execute;
}


//OTHER
void		AForm::beSigned(Bureaucrat const & bur){
	if (bur.getGrade() > _required_grade_sign)
	{
		bur.signForm(*this);
		throw GradeTooLowException();
	}
	_is_signed = true;
	bur.signForm(*this);
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (_is_signed == false)
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredGradeExecute())
		throw GradeTooLowException();
	form_action();
}

//PRINT
std::ostream	&operator<<(std::ostream &out, AForm const &form){
	out<<"Form "<<form.getName()<<", ";
	if (form.getIsSigned() == true)
		out<<"(signed), ";
	else
		out<<"(NOT signed), ";
	out<<"required grade for signing ["<<form.getRequiredGradeSign()<<"] and for executing ["<<form.getRequiredGradeExecute()<<"]\n";
	return out;
}