/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 15:25:28 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	initBurGradeTooLow()
{
	std::cout<<"\nTESTING INITIALIZATION OF OBJECT WITH LOW GRADE\n\n";
	try {
		Bureaucrat bur1("One", 150);
		std::cout<<bur1;
		Bureaucrat bur2("Two", 151);
		std::cout<<bur2;
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}

void	initBurGradeTooHigh()
{
	std::cout<<"\nTESTING INITIALIZATION OF OBJECT WITH HIGH GRADE\n\n";
	try {
		Bureaucrat bur1("One", 1);
		std::cout<<bur1;
		Bureaucrat bur2("Two", 0);
		std::cout<<bur2;
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}

void	testGetters()
{
	std::cout<<"\nTESTING GUETTERS AND OPERATOR << \n\n";
	Bureaucrat bur("Random", 5);
	std::cout<<"getName()-> "<<bur.getName()<<"\n";
	std::cout<<"getGrade()-> "<<bur.getGrade()<<"\n";
	std::cout<<"'printing' class details with << operator\n";
	std::cout<<bur;
}

void	testIncrement()
{
	std::cout<<"\nTESTING INCREMENT MEMBER FT\n\n";
	Bureaucrat bur("example", 150);
	std::cout<<bur;
	try {
		bur.increaseGrade(100);
		std::cout<<bur;
		bur.increaseGrade(49);
		std::cout<<bur;
		bur.increaseGrade(1);
		std::cout<<bur;
	}catch(std::exception &e){
		std::cout<<e.what()<<"\n";
	}
}

void	testDecrement()
{
	std::cout<<"\nTESTING DECREMEN T MEMBER FT\n\n";
	Bureaucrat bur("example", 1);
	std::cout<<bur;
	try {
		bur.decreaseGrade(120);
		std::cout<<bur;
		bur.decreaseGrade(29);
		std::cout<<bur;
		bur.decreaseGrade(1);
		std::cout<<bur;
	}catch(std::exception &e){
		std::cout<<e.what()<<"\n";
	}
}


int	main(void)
{
	initBurGradeTooLow();
	initBurGradeTooHigh();
	testGetters();
	testIncrement();
	testDecrement();
}