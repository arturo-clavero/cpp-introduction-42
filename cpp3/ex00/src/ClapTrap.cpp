/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:12 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:59:54 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//member functions
void	ClapTrap::attack(const std::string& target) {
	if (EnergyPoints == 0)
	{
		std::cout<<"ClapTrap "<<Name<<" failed to attack "<<target<<", (No energy points!)\n";
		return ;
	}
	std::cout<<"ClapTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!\n";
	EnergyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	modifiedAmount = -1;
	if (HitPoints - (int)amount < 0)
		modifiedAmount = HitPoints;
	if (modifiedAmount == 0)
		std::cout<<"ClapTrap "<<Name<<" has been attacked with "<<amount<<" points of damage, but" <<Name<<" has no hit points left\n";
	else if (modifiedAmount != -1)
	{
		std::cout<<"ClapTrap "<<Name<<" has been attacked with "<<amount<<" points of damage, loosing" <<modifiedAmount<<" hit points!\n";
		amount = modifiedAmount;
	}
	else
		std::cout<<"ClapTrap "<<Name<<" has been attacked, loosing "<<amount<<" hit points!\n";
	HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (EnergyPoints == 0)
	{
		std::cout<<"ClapTrap "<<Name<<" failed to repair it self, (No energy points!)\n";
		return ;
	}
	std::cout<<"ClapTrap "<<Name<<" has been repaired, gaining "<<amount<<" hit points!\n";
	HitPoints += amount;
	EnergyPoints--;
}

void	ClapTrap::printStats() {
	std::cout<<Name<<" : hit("<<HitPoints<<"), energy("<<EnergyPoints<<")\n";
}

//ORTHODOX FORMAT
ClapTrap::ClapTrap() {
	std::cout<<"Default constructor called\n";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	Name = "";
}

ClapTrap::ClapTrap(std::string Name) {
	std::cout<<"Constructor with params called\n";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	this->Name = Name;
}

ClapTrap::ClapTrap(ClapTrap &Original) {
	std::cout<<"Copy constructor called\n";
	AttackDamage = Original.AttackDamage;
	EnergyPoints = Original.EnergyPoints;
	HitPoints = Original.HitPoints;
	Name = Original.Name;
}
	
ClapTrap	&ClapTrap::operator=(ClapTrap const &Original) {
	std::cout<<"Copy assignment operator called\n";
	AttackDamage = Original.AttackDamage;
	EnergyPoints = Original.EnergyPoints;
	HitPoints = Original.HitPoints;
	Name = Original.Name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout<<"Destructor called\n";
}
