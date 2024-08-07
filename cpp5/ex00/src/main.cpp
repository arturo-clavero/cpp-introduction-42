/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:36:15 by artclave          #+#    #+#             */
/*   Updated: 2024/08/07 19:16:16 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_construction_grade_too_high(){
	std::cout<<"\nCONSTRUCT TOO HIGH:\n";
	try {
		Bureaucrat	bur1("Jim", 1);
		Bureaucrat	bur2("Wrong", 0);
		std::cout<<"This will only print if both burs have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}


void	test_construction_grade_too_low(){
	std::cout<<"\nCONSTRUCT TOO LOW:\n";
	try {
		Bureaucrat	bur1("Jim", 150);
		Bureaucrat	bur2("Wrong", 151);
		std::cout<<"This will only print if both burs have correct grades...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}

void	test_increment_grade(){
	std::cout<<"\n\nINCREMENT:\n";
	try{
		Bureaucrat	bur1("Jim", 10);
		bur1.incrementGrade(5);
		bur1.incrementGrade(5);
		std::cout<<"This will only print if both promotions are successful...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}

void	test_decrement_grade(){
	std::cout<<"\n\nDECREMENT:\n";
	try{
		Bureaucrat	bur1("Jim", 141);
		bur1.decrementGrade(5);
		bur1.decrementGrade(5);
		std::cout<<"This will only print if both demotions are successful...\n";
	}
	catch (std::exception &e){
		std::cout<<e.what();
	}
}

int	main(void)
{
	test_construction_grade_too_high();
	test_construction_grade_too_low();
	test_increment_grade();
	test_decrement_grade();
}
