/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:00:07 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 18:48:16 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class	Bureaucrat{
	private:
		std::string	const	name;
		int					grade;
	public:
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
		Bureaucrat();
		Bureaucrat(const std::string name_param, int grade);
		Bureaucrat(Bureaucrat const &original);
		Bureaucrat	&operator=(Bureaucrat const &original);
		~Bureaucrat();
		std::string	getName();
		int	getGrade() const;
		void	increaseGrade(int amount);
		void	decreaseGrade(int amount);
		void	executeForm(AForm const & form);
};

std::ostream	&operator<<(std::ostream &cout_param, Bureaucrat &bur);

#endif