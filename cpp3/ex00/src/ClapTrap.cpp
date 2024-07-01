/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:12 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 17:32:36 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//member functions
void	ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0)
	{
		std::cout<<"ClapTrap "<<name<<" failed to attack "<<target<<", (No energy points!)\n";
		return ;
	}
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!\n";
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	modifiedAmount = -1;
	if (hitPoints - (int)amount < 0)
		modifiedAmount = hitPoints;
	if (modifiedAmount == 0)
		std::cout<<"ClapTrap "<<name<<" has been attacked with "<<amount<<" points of damage, but" <<name<<" has no hit points left\n";
	else if (modifiedAmount != -1)
	{
		std::cout<<"ClapTrap "<<name<<" has been attacked with "<<amount<<" points of damage, loosing" <<modifiedAmount<<" hit points!\n";
		amount = modifiedAmount;
	}
	else
		std::cout<<"ClapTrap "<<name<<" has been attacked, loosing "<<amount<<" hit points!\n";
	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0)
	{
		std::cout<<"ClapTrap "<<name<<" failed to repair it self, (No energy points!)\n";
		return ;
	}
	std::cout<<"ClapTrap "<<name<<" has been repaired, gaining "<<amount<<" hit points!\n";
	hitPoints += amount;
	energyPoints--;
}

void	ClapTrap::printStats() {
	std::cout<<"ClapTrap "<<name<<" : hit("<<hitPoints<<"), energy("<<energyPoints<<")\n";
}

//ORTHODOX FORMAT
ClapTrap::ClapTrap() {
	std::cout<<"Default constructor called for class 'ClapTrap'\n";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	name = "";
}

ClapTrap::ClapTrap(std::string name) {
	std::cout<<"Constructor with params called for class 'ClapTrap'\n";
	hitPoints = 10; 
	energyPoints = 10;
	attackDamage = 0;
	this->name = name;
}

ClapTrap::ClapTrap(ClapTrap &original) {
	std::cout<<"Copy constructor called for class 'ClapTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}
	
ClapTrap	&ClapTrap::operator=(ClapTrap const &original) {
	std::cout<<"Copy assignment operator called for class 'ClapTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout<<"Destructor called for class 'ClapTrap'\n";
}
