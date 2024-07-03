/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 03:09:54 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	//testAFormValues
	//testTooLowToSign
	//testTooLowToExec
	//testExecShrubb
	//testExecRobot
	//testExecPresi
	Bureaucrat bur("Mr. Guy", 1);
	PresidentialPardonForm form("home");
	std::cout<<"\n"<<form<<"\n";
	form.beSigned(bur);
	bur.executeForm(form);
	std::cout<<"\n";
}