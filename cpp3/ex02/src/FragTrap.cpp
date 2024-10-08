/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:44:24 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:57:10 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void){
	std::cout<<"Positive high five request...\n";
}

//ORTHODOX FORMAT
FragTrap::FragTrap() {
	std::cout<<"Default constructor called for class 'FragTrap'\n";
	name = "";
	attackDamage = 30;
	energyPoints = 100;
	hitPoints = 100;
}

FragTrap::FragTrap(const std::string &name) {
	std::cout<<"Constructor with params called for class 'FragTrap'\n";
	this->name = name;
	attackDamage = 30;
	energyPoints = 100;
	hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original) {
	std::cout<<"Copy constructor called for class 'FragTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}

FragTrap	&FragTrap::operator=(const FragTrap &original) {
	std::cout<<"Copy assignment operator called for class 'FragTrap'\n";
	ClapTrap::operator=(original);
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout<<"Destructor called for class 'FragTrap'\n";
}
