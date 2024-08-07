/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:16:36 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 21:37:39 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_construction_grade_too_high(){
	std::cout<<"\nCONSTRUCT TOO HIGH:\n";
	try {
		Form	form1("(A)", 20, 10);
		Form	form2("(B)", 0, 10);
		std::cout<<"This will only print if both forms have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
	std::cout<<"\n";
	try {
		Form	form1("(C)", 20, 10);
		Form	form2("(D)", 20, 0);
		std::cout<<"This will only print if both forms have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}

void	test_construction_grade_too_low(){
	std::cout<<"\nCONSTRUCT TOO LOW:\n";
	try {
		Form	form1("(A)", 20, 10);
		Form	form2("(B)", 151, 10);
		std::cout<<"This will only print if both forms have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
	std::cout<<"\n";
	try {
		Form	form1("(C)", 20, 10);
		Form	form2("(D)", 20, 151);
		std::cout<<"This will only print if both forms have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}

void	test_sign_form(){
	std::cout<<"\nSIGN::\n";
	try {
		Form		form("(A)", 20, 10);
		Bureaucrat	ana("Ana", 20);
		Bureaucrat	tom("Tom", 21);
		ana.signForm(form);
		form.beSigned(ana);
		//ana.signForm(form);
		form.beSigned(tom);
		//tom.signForm(form);
		std::cout<<"This will only print if both bureaucrats have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}

}

int	main(void){
	test_construction_grade_too_high();
	test_construction_grade_too_low();
	test_sign_form();
}