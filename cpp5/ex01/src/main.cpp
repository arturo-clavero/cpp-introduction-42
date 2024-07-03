/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 16:41:00 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	testDefaultConstructor()
{
	std::cout<<"\nTEST DEFAULT CONSTRUCTOR:\n";
	Form	form;
}

void	testConstructor()
{
	std::cout<<"\nTEST CONSTRUCTOR WITH PARAMS:\n";
	Form	form("new form");
}

void	testCopyConstructor()
{
	std::cout<<"\nTEST COPY CONSTRUCTOR:\n";
	Form form1("one");
	Form form2(form1);
}

void	testCopyAssignmentOperator()
{
	std::cout<<"\nTEST COPY ASSIGNMENT OPERATOR:\n";
	Form form1("one");
	Form form2("two");
	form2 = form1;
}

void	testOrthodox()
{
	testDefaultConstructor();
	testConstructor();
	testCopyConstructor();
	testCopyAssignmentOperator();
}

void	testGetters()
{
	std::cout<<"\nTEST GETTERS\n";
	Form form("one");
	std::cout<<"getExecGrade()= "<<form.getExecGrade()<<"\n";
	std::cout<<"getIsSigned()= "<<form.getIsSigned()<<"\n";
	std::cout<<"getName()= "<<form.getName()<<"\n";
	std::cout<<"getSignGrade()= "<<form.getSignGrade()<<"\n";
}

void	testBeSigned()
{
	std::cout<<"\nTEST BE SIGNED FT\n";
	Bureaucrat bur("Mr.Bur", 1);
	Form form("one");
	Form form2("two");
	try{
		form.beSigned(bur);
		bur.decreaseGrade(1);
		form2.beSigned(bur);
	}catch(std::exception &e){
		std::cout<<"Error: "<<e.what()<<"\n";
	}
}

void	testSignForm()
{
	std::cout<<"\nTEST SIGN FORM FT\n";
	Bureaucrat bur("Mr.Bur", 1);
	Form form("one");
	Form form2("two");
	std::cout<<"\n";
	try{
		form.signForm(bur);
		form.beSigned(bur);
		form.signForm(bur);
		bur.decreaseGrade(1);
		form2.signForm(bur);
	}catch(std::exception &e){
		std::cout<<"Error: "<<e.what()<<"\n";
	}
	std::cout<<"\n";
}

int	main(void)
{
	testOrthodox();
	testGetters();
	testBeSigned();
	testSignForm();
}