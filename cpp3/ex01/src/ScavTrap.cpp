/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:06:28 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:47:28 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//member functions
void	ScavTrap::guardGate() {
	std::cout<<"ScavTrap is now in Gate keeper mode.\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (energyPoints == 0)
	{
		std::cout<<"SCAVPTRAP "<<name<<" failed to attack "<<target<<", (No energy points!)\n";
		return ;
	}
	std::cout<<"SCAVTRAP "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!\n";
	energyPoints--;
}

//ORTHODOX FORMAT
ScavTrap::ScavTrap() {
	std::cout<<"Default constructor called for class 'ScavTrap'\n";
	name = "";
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

ScavTrap::ScavTrap(const std::string &name) {
	std::cout<<"Constructor with params called for class 'ScavTrap'\n";
	this->name = name;
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original) {
	std::cout<<"Copy constructor called for class 'ScavTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &original) {
	std::cout<<"Copy assignment operator called for class 'ScavTrap'\n";
	ClapTrap::operator=(original);
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout<<"Destructor called for class 'ScavTrap'\n";
}