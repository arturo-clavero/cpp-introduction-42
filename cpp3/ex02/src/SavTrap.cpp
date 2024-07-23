/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SavTrap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:06:28 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:47:59 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SavTrap.hpp"

//member functions
void	SavTrap::guardGate() {
	std::cout<<"ScavTrap is now in Gate keeper mode.\n";
}

//ORTHODOX FORMAT
SavTrap::SavTrap() {
	std::cout<<"Default constructor called for class 'SavTrap'\n";
	name = "";
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

SavTrap::SavTrap(const std::string &name) {
	std::cout<<"Constructor with params called for class 'SavTrap'\n";
	this->name = name;
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

SavTrap::SavTrap(const SavTrap &original) : ClapTrap(original) {
	std::cout<<"Copy constructor called for class 'SavTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}

SavTrap	&SavTrap::operator=(const SavTrap &original) {
	std::cout<<"Copy assignment operator called for class 'SavTrap'\n";
	ClapTrap::operator=(original);
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
	return *this;
}

SavTrap::~SavTrap() {
	std::cout<<"Destructor called for class 'SavTrap'\n";
}