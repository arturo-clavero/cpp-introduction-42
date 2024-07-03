/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 03:44:54 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testExecShrub()
{
	Bureaucrat bur("Mr. Guy", 137);
	ShrubberyCreationForm form("random target");
	std::cout<<"\n"<<form<<"\n";
	form.beSigned(bur);
	bur.executeForm(form);
	std::cout<<"\n";
}

void	testExecRobot()
{
	Bureaucrat bur("Mr. Guy", 45);
	RobotomyRequestForm form("random target");
	std::cout<<"\n"<<form<<"\n";
	form.beSigned(bur);
	bur.executeForm(form);
	std::cout<<"\n";
}

void	testExecPresi()
{
	Bureaucrat bur("Mr. Guy", 5);
	PresidentialPardonForm form("random target");
	std::cout<<"\n"<<form<<"\n";
	form.beSigned(bur);
	bur.executeForm(form);
	std::cout<<"\n";
}

void	testAFormValues()
{
	std::cout<<"Let's test if we can initialize the AForm's values correctly for each concrete class\n";
	std::cout<<"\nTest 1: ShrubberyCreationForm: Required grades: sign 145, exec 137:\n";
	ShrubberyCreationForm form1;
	std::cout<<form1;
	std::cout<<"\nTest 2: RobotomyRequestForm: Required grades: sign 72, exec 45:\n";
	RobotomyRequestForm form2;
	std::cout<<form2;
	std::cout<<"\nTest 3: PresidentialPardonForm: Required grades: sign 25, exec 5:\n";
	PresidentialPardonForm form3;
	std::cout<<form3;
	std::cout<<"\nWe can see all values match, lets destroy these forms...\n\n";
}

void	testTooLowToSign()
{
	std::cout<<"Let's test if grades lower than required sign grade stop execution of forms\n";
	Bureaucrat bur("Mr. Guy", 146);
	std::cout<<"\nTest 1: ShrubberyCreationForm: Required grades: sign 145\n\n";
	ShrubberyCreationForm form1;
	std::cout<<bur<<form1;
	try{
	form1.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form1);
	std::cout<<"\n\nTest 2: RobotomyRequestForm: Required grades: sign 72\n\n";
	RobotomyRequestForm form2;
	bur.increaseGrade(73);
	std::cout<<bur<<form2;
	try{
	form2.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form2);
	std::cout<<"\nTest 3: PresidentialPardonForm: Required grades: sign 25\n\n";
	PresidentialPardonForm form3;
	bur.increaseGrade(47);
	std::cout<<bur<<form3;
	try{
	form3.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form3);	
	std::cout<<"\n\nend of test, now destroy:\n\n";
}

void	testTooLowToExec()
{
	std::cout<<"Let's test if grades lower than required execution grade stop execution of forms\n";
	Bureaucrat bur("Mr. Guy", 138);
	std::cout<<"\nTest 1: ShrubberyCreationForm: Required grades: exec 137\n\n";
	ShrubberyCreationForm form1;
	std::cout<<bur<<form1;
	try{
	form1.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form1);
	std::cout<<"\n\nTest 2: RobotomyRequestForm: Required grades: exec 45\n\n";
	RobotomyRequestForm form2;
	bur.increaseGrade(92);
	std::cout<<bur<<form2;
	try{
	form2.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form2);
	std::cout<<"\nTest 3: PresidentialPardonForm: Required grades: exec 5\n\n";
	PresidentialPardonForm form3;
	bur.increaseGrade(40);
	std::cout<<bur<<form3;
	try{
	form3.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<e.what();
	}
	bur.executeForm(form3);	
	std::cout<<"\n\nend of test, now destroy:\n\n";
}

int	main(void)
{
	testAFormValues();
	testTooLowToSign();
	testTooLowToExec();
	testExecShrub();
	testExecRobot();
	testExecPresi();
}