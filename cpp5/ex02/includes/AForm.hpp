/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:37:40 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 02:12:04 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;

class	AForm{
	private:
		std::string	const	_name;
		bool				_is_signed;
		int	const			_required_grade_sign;
		int	const			_required_grade_execute;
	public:
	//orthodox
		AForm(std::string const &name, const int sign, const int exec);
		AForm(AForm const & og);
		AForm	&operator=(AForm const & og);
		virtual ~AForm() = 0;
	//getter
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;
	//other
		void			beSigned(Bureaucrat const & bur);
		void			execute(Bureaucrat const & executor) const;
		virtual void	form_action() const = 0;
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
		class	FormNotSignedException : public std::exception{
			const char *what() const throw(){
				return "Form not signed\n";
			}
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif