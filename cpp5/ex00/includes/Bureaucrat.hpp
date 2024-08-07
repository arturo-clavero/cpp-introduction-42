/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:06:42 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:38 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

/*
A constant name.
• And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
grade)*/

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