/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:06:42 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 21:13:12 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

/*
Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and turn in some tests to ensure everything works as expected.
*/

#include "Form.hpp"

class Form;

class	Bureaucrat{
	private:
		std::string	const	_name;
		int					_grade;
	public:
//orthodox
	Bureaucrat(std::string const &name, int const grade);
	Bureaucrat(Bureaucrat const &og);
	Bureaucrat	&operator=(Bureaucrat const &og);
	~Bureaucrat();
//getters
	std::string	getName() const;
	int			getGrade() const;
//others
	void	incrementGrade(int const amount);
	void	decrementGrade(int const amount);
	void	signForm(Form const & form) const;
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

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bur);
#endif