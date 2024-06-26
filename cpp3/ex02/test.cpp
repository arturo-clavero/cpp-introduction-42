/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:03:02 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 20:22:59 by arturo           ###   ########.fr       */
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

class	FragTrap : public ClapTrap
{
	private:
	//
	public:
	//member functions
		void highFivesGuys(void){
				std::cout<<"Positive high five request...\n";
		}
		void	attack(const std::string& target) {
			if (EnergyPoints == 0)
			{
				std::cout<<"FragTrap "<<Name<<" failed to attack "<<target<<", (No energy points!)\n";
				return ;
			}
			std::cout<<"FragTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!\n";
			EnergyPoints--;
		}
		void	printStats() {
			std::cout<<"FragTrap "<<Name<<" : hit("<<HitPoints<<"), energy("<<EnergyPoints<<")\n";
		}
	//ORTHODOX FORMAT
		FragTrap() {
			std::cout<<"FragTrap default constructor called\n";
			Name = "";
			AttackDamage = 30;
			EnergyPoints = 100;
			HitPoints = 100;
		}
		FragTrap(std::string Name) {
			std::cout<<"FragTrap constructor with params called\n";
			this->Name = Name;
			AttackDamage = 30;
			EnergyPoints = 100;
			HitPoints = 100;
		}
		FragTrap(FragTrap &Original) {
			std::cout<<"FragTrap copy constructor called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
		}
		FragTrap	&operator=(FragTrap const &Original) {
			std::cout<<"FragTrap copy assignment operator called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
			return *this;
		}
		~FragTrap() {
			std::cout<<"FragTrap constructor called\n";
		}
};