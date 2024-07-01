/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SavTrap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:52 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 17:20:50 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVTRAP_HPP
# define SAVTRAP_HPP

#include "ClapTrap.hpp"

class	SavTrap : public ClapTrap
{
	private:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;
	public:
	//member functions
		void	guardGate();
		void	attack(const std::string& target);
		void	printStats();
	//ORTHODOX FORMAT
		SavTrap();
		SavTrap(std::string name);
		SavTrap(SavTrap &original);
		SavTrap	&operator=(SavTrap const &original);
		~SavTrap();
};

#endif