/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:37:40 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 21:28:16 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class	Form{
	private:
		std::string	const	_name;
		bool				_is_signed;
		int	const			_required_grade_sign;
		int	const			_required_grade_execute;
	public:
	//orthodox
		Form(std::string const &name, const int sign, const int exec);
		Form(Form const & og);
		Form	&operator=(Form const & og);
		~Form();
	//getter
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;
	//other
		void		beSigned(Bureaucrat const & bur);
	//exceptions
		class	GradeTooHighException : public std::exception{
			const char *what() const throw(){
				return "Grade too high\n";
			}
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw(){
				return "Grade too low\n";
			}
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif