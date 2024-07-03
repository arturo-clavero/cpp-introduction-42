/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:57:30 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 04:23:00 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm, public Form{
	
	private:
		std::string	const	name;
		std::string			target;
		bool				isSigned;
		int	const			signGrade;
		int	const			execGrade;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm();
		void	performTask() const;
};

#endif