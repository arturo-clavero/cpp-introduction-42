/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:49:23 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 02:00:44 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class	AForm{
	private:
		std::string	const	name;
		bool				isSigned;
		int	const			signGrade;
		int	const			execGrade;
	public:
		class	GradeTooHighException : public std::exception{
			const char *what() const throw(){
				return "Error: Grade too high\n";
			}
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw(){
				return "Error: Grade too low\n";
			}
		};
		AForm();
		AForm(const std::string name_param, int signGrade_param, int execGrade_param);
		AForm(AForm const &original);
		AForm	&operator=(AForm const &original);
		~AForm();
		std::string	getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		int	getIsSigned() const;
		void	beSigned(Bureaucrat &bur);
		void	signForm(Bureaucrat &bur);
		virtual void performTask() const = 0;
		void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &cout_param, AForm &form);

#endif