/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:03:02 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 20:23:14 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	Name;
		int	HitPoints{10};
		int	EnergyPoints{10};
		int	AttackDamage{0};
	
	public:
	//member functions
		void	attack(const std::string& target) {
			if (EnergyPoints == 0)
			{
				std::cout<<"ClapTrap "<<Name<<" failed to attack "<<target<<", (No energy points!)\n";
				return ;
			}
			std::cout<<"ClapTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!\n";
			EnergyPoints--;
		}
		void	takeDamage(unsigned int amount) {
			int	modifiedAmount {-1};
			if (HitPoints - amount < 0)
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
		void	beRepaired(unsigned int amount) {
			if (EnergyPoints == 0)
			{
				std::cout<<"ClapTrap "<<Name<<" failed to repair it self, (No energy points!)\n";
				return ;
			}
			std::cout<<"ClapTrap "<<Name<<" has been repaired, gaining "<<amount<<" hit points!\n";
			HitPoints += amount;
			EnergyPoints--;
		}
		void	printStats() {
			std::cout<<"ClapTrap "<<Name<<" : hit("<<HitPoints<<"), energy("<<EnergyPoints<<")\n";
		}
	//ORTHODOX FORMAT
		ClapTrap() {
			std::cout<<"ClapTrap default constructor called\n";
			this->Name = "";
		}
		ClapTrap(std::string Name) {
			std::cout<<"ClapTrap constructor with params called\n";
			this->Name = Name;
		}
		ClapTrap(ClapTrap &Original) {
			std::cout<<"ClapTrap copy constructor called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
		}
		ClapTrap	&operator=(ClapTrap const &Original) {
			std::cout<<"ClapTrap copy assignment operator called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
			return *this;
		}
		~ClapTrap() {
			std::cout<<"ClapTrap destructor called\n";
		}
};

class	SavTrap : public ClapTrap
{
	private:
	//
	public:
	//member functions
		void	guardGate() {
			std::cout<<"ScavTrap is now in Gate keeper mode.\n";
		}
		void	attack(const std::string& target) {
			if (EnergyPoints == 0)
			{
				std::cout<<"SavTrap "<<Name<<" failed to attack "<<target<<", (No energy points!)\n";
				return ;
			}
			std::cout<<"SavTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!\n";
			EnergyPoints--;
		}
		void	printStats() {
			std::cout<<"SavTrap "<<Name<<" : hit("<<HitPoints<<"), energy("<<EnergyPoints<<")\n";
		}
	//ORTHODOX FORMAT
		SavTrap() {
			std::cout<<"SavTrap default constructor called\n";
			Name = "";
			AttackDamage = 20;
			EnergyPoints = 50;
			HitPoints = 100;
		}
		SavTrap(std::string Name) {
			std::cout<<"SavTrap constructor with params called\n";
			this->Name = Name;
			AttackDamage = 20;
			EnergyPoints = 50;
			HitPoints = 100;
		}
		SavTrap(SavTrap &Original) {
			std::cout<<"SavTrap copy constructor called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
		}
		SavTrap	&operator=(SavTrap const &Original) {
			std::cout<<"SavTrap copy assignment operator called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
			return *this;
		}
		~SavTrap() {
			std::cout<<"SavTrap constructor called\n";
		}
};