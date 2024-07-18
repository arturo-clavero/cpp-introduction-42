/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SavTrap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:06:28 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 19:03:34 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SavTrap.hpp"

//member functions
void	SavTrap::guardGate() {
	std::cout<<"ScavTrap is now in Gate keeper mode.\n";
}

void	SavTrap::attack(const std::string& target) {
	if (energyPoints == 0)
	{
		std::cout<<"SavTrap "<<name<<" failed to attack "<<target<<", (No energy points!)\n";
		return ;
	}
	std::cout<<"SavTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!\n";
	energyPoints--;
}

void	SavTrap::printStats() {
	std::cout<<"SavTrap "<<name<<" : hit("<<hitPoints<<"), energy("<<energyPoints<<")\n";
}

//ORTHODOX FORMAT
SavTrap::SavTrap() {
	std::cout<<"Default constructor called for class 'SavTrap'\n";
	name = "";
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

SavTrap::SavTrap(std::string name) {
	std::cout<<"Constructor with params called for class 'SavTrap'\n";
	this->name = name;
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

SavTrap::SavTrap(SavTrap const &original) : ClapTrap(original) {
	std::cout<<"Copy constructor called for class 'SavTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}

SavTrap	&SavTrap::operator=(SavTrap const &original) {
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