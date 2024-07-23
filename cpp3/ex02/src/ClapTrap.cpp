/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:12 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:56:18 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//member functions
void	ClapTrap::attack(const std::string &target) {
	if (energyPoints == 0)
	{
		std::cout<<name<<" failed to attack "<<target<<", (No energy points!)\n";
		return ;
	}
	std::cout<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!\n";
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	modifiedAmount = -1;
	if (hitPoints - (int)amount < 0)
		modifiedAmount = hitPoints;
	if (hitPoints == 0)
		std::cout<<name<<" has been attacked with "<<amount<<" points of damage, but" <<name<<" has no hit points left\n";
	else if (modifiedAmount != -1)
	{
		std::cout<<name<<" has been attacked with "<<amount<<" points of damage, loosing" <<modifiedAmount<<" hit points!\n";
		amount = modifiedAmount;
	}
	else
		std::cout<<name<<" has been attacked, loosing "<<amount<<" hit points!\n";
	hitPoints -= amount;
}

void	ClapTrap::beRepaired(const unsigned int &amount) {
	if (energyPoints == 0)
	{
		std::cout<<name<<" failed to repair it self, (No energy points!)\n";
		return ;
	}
	std::cout<<name<<" has been repaired, gaining "<<amount<<" hit points!\n";
	hitPoints += amount;
	energyPoints--;
}

void	ClapTrap::printStats() {
	std::cout<<name<<" : hit("<<hitPoints<<"), energy("<<energyPoints<<")\n";
}

//ORTHODOX FORMAT
ClapTrap::ClapTrap() {
	std::cout<<"Default constructor called for class 'ClapTrap'\n";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	name = "";
}

ClapTrap::ClapTrap(const std::string &name) {
	std::cout<<"Constructor with params called for class 'ClapTrap'\n";
	hitPoints = 10; 
	energyPoints = 10;
	attackDamage = 0;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &original) {
	std::cout<<"Copy constructor called for class 'ClapTrap'\n";
	attackDamage = original.attackDamage;
	energyPoints = original.energyPoints;
	hitPoints = original.hitPoints;
	name = original.name;
}
	
ClapTrap	&ClapTrap::operator=(const ClapTrap &original) {
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
