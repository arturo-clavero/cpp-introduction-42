/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:48:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 05:37:55 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <cstddef>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern{
	
	private:
		Form	*makeRobot(std::string target);
		Form	*makeShrub(std::string target);
		Form	*makePresi(std::string target);
	
	public:
		Form	*makeForm(std::string type, std::string target);
		Intern();
		Intern(Intern &original);
		Intern	&operator=(Intern &original);
		~Intern();
};

#endif