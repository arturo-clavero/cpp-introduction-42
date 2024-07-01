/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:50:47 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:59:11 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
		std::string	Name;
		int	HitPoints;
		int	EnergyPoints;
		int	AttackDamage;
	
	public:
	//member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStats();
	//ORTHODOX FORMAT
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(ClapTrap &Original);
		ClapTrap	&operator=(ClapTrap const &Original);
		~ClapTrap();
};

#endif