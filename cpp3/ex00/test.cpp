/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:51:22 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 19:41:24 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ClapTrap
{
	private:
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
			std::cout<<Name<<" : hit("<<HitPoints<<"), energy("<<EnergyPoints<<")\n";
		}
	//ORTHODOX FORMAT
		ClapTrap() {
			std::cout<<"Default constructor called\n";
			this->Name = nullptr;
		}
		ClapTrap(std::string Name) {
			std::cout<<"Constructor with params called\n";
			this->Name = Name;
		}
		ClapTrap(ClapTrap &Original) {
			std::cout<<"Copy constructor called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
		}
		ClapTrap	&operator=(ClapTrap const &Original) {
			std::cout<<"Copy assignment operator called\n";
			AttackDamage = Original.AttackDamage;
			EnergyPoints = Original.EnergyPoints;
			HitPoints = Original.HitPoints;
			Name = Original.Name;
			return *this;
		}
		~ClapTrap() {
			std::cout<<"Destructor called\n";
		}
};

int	main(void)
{
	ClapTrap	Red("red team");
	ClapTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
	Red.printStats();
	Blue.printStats();
	Blue.beRepaired(5);
	Blue.printStats();
}