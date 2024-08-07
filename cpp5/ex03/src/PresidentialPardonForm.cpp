/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:46:44 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 00:43:24 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//ORTHODOX

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", 25, 5),
																	_target(target),
																	_required_grade_sign(25),
																	_required_grade_execute(5)
{
	std::cout<<"Constructor called for "<<*this;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & og): AForm(og), 
																				  _target(og.getTarget()),
																				  _required_grade_sign(og.getRequiredGradeSign()),
																				  _required_grade_execute(og.getRequiredGradeExecute())
{
	std::cout<<"Copy constructor called for "<<*this;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & og) {
	_target = og.getTarget();
	std::cout<<"Copy assignment operator called for "<<*this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout<<"Destructor called for "<<*this;
}

//GETTERS
std::string	PresidentialPardonForm::getTarget() const{
	return _target;
}

int	PresidentialPardonForm::getRequiredGradeSign()const{
	return _required_grade_sign;
}

int	PresidentialPardonForm::getRequiredGradeExecute()const{
	return _required_grade_execute;
}

//OTHER
void	PresidentialPardonForm::form_action()const{
	std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox.\n";
}

//PRINT
std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const & form){
	out<<"Presidential Pardon Form with target: "<<form.getTarget()<<", required grade for signing ["<<form.getRequiredGradeSign()<<"], and for executing ["<<form.getRequiredGradeExecute()<<"]\n";
	return out;
}