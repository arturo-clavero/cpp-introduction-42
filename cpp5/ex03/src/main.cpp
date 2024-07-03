/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 06:10:40 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testRobo()
{
	Intern	intern;
	Form *form1;
	form1 = intern.makeForm("robotomy request", "home");
	if (form1 != NULL)
	{
		std::cout<<*form1;
		delete form1;
	}
}

void	testPresi()
{
	Intern	intern;
	Form *form3;
	form3 = intern.makeForm("presidential request", "home");
	if (form3 != NULL)
	{
		std::cout<<*form3;
		delete form3;
	}
}

void	testShrub()
{
	Intern	intern;
	Form *form3;
	form3 = intern.makeForm("shrubbery request", "home");
	if (form3 != NULL)
	{
		std::cout<<*form3;
		delete form3;
	}
}

void	testWrong()
{
	Intern intern;
	Form *form4;
	form4 = intern.makeForm("alian request", "home");
	if (form4 != NULL)
	{
		std::cout<<*form4;
		delete form4;
	}
}
int	main(void)
{
	testRobo();
	testPresi();
	testShrub();
	testWrong();
}