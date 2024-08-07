/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:16:36 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 02:38:13 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	testExecShrub()
{
	std::cout<<"\n";
	Bureaucrat bur("Mr. Guy", 137);
	ShrubberyCreationForm form("random");
	form.beSigned(bur);
	bur.executeForm(form);
}

void	testExecRobot()
{
	std::cout<<"\n";
	Bureaucrat bur("Mr. Guy", 45);
	RobotomyRequestForm form("random");
	form.beSigned(bur);
	bur.executeForm(form);
}

void	testExecPresi()
{
	std::cout<<"\n";
	Bureaucrat bur("Mr. Guy", 5);
	PresidentialPardonForm form("random");
	form.beSigned(bur);
	bur.executeForm(form);
}

int	main(void){
	testExecShrub();
	std::cout<<"\n";
	testExecPresi();
	std::cout<<"\n";
	testExecRobot();
	std::cout<<"\n";
}