/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:15:23 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 05:28:51 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), Form("robotomy request", 72, 45), name("Robotomy Request"), target("default"), signGrade(72), execGrade(45){
	std::cout<<"Default constructor called for Robotomy\n";
	isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), Form("robotomy request", 72, 45), name("Robotomy Request"), target("default"), signGrade(72), execGrade(45) {
	std::cout<<"Constructor called for Robotomy with target "<<target<<"\n";
	isSigned = false;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm("Robotomy Request", 72, 45), Form("robotomy request", 72, 45), name("Robotomy Request"), target("default"), signGrade(72), execGrade(45){
	std::cout<<"Copy constructor called for Robotomy\n";
	isSigned = original.isSigned;
	target = original.target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &original){
	std::cout<<"Copy assignment operator called for Robotomy\n";
	isSigned = original.isSigned;
	target = original.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout<<"Destructor called for Robotomy with target "<<target<<"\n";
}

void	RobotomyRequestForm::performTask() const{
	std::cout<<"\n⠀⢀⣤⡤⠤⠤⠤⠤⠤⠤⠤⠤⠤⢤⣤⡄⢠⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⣼⣿⡇⣠⣤⣤⣤⣤⣤⣤⣤⡄⢸⣿⡇⢸⣿⡇⣿⣿⠀⣿⣿⣦⠀⣤⣤⣤⠀\n⠀⢹⣿⣇⣉⣉⣉⣉⣉⣉⣉⣉⣁⣸⣿⡇⢸⣿⡇⠿⠿⠀⠛⠛⠉⠀⠀⠀⠀⠀\n⠀⠀⠉⠉⠙⠛⢿⣿⣿⣿⣿⡟⠛⠛⠛⠃⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⢀⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⣼⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠰⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⣤⣤⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⢀⣶⣶⣿⣿⣿⣿⣿⣶⣶⣶⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⢀⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠘⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\rrrrrRRRRATATATATATATAAAAA\n\n";
	std::srand(std::time(0));
	int	success = std::rand() % 2;
	if (success)
		std::cout<<target<<" has been robotomized successfully\n";
	else
		std::cout<<"Robotomy failed\n";
}