/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:28:09 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 16:08:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Form{
	private:
		std::string	const	name;
		bool				isSigned;
		int	const			signGrade;
		int	const			execGrade;
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
		Form();
		Form(const std::string name_param);
		Form(Form const &original);
		Form	&operator=(Form const &original);
		~Form();
		std::string	getName();
		int	getSignGrade();
		int	getExecGrade();
		int	getIsSigned();
		void	beSigned(Bureaucrat &bur);
		void	signForm(Bureaucrat &bur);
};

# endif