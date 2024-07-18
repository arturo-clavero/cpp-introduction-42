/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:50:47 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 19:03:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;
	
	public:
	//member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStats();
	//ORTHODOX FORMAT
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &original);
		ClapTrap	&operator=(ClapTrap const &original);
		~ClapTrap();
};

#endif