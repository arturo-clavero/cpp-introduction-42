/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:52 by arturo            #+#    #+#             */
/*   Updated: 2024/07/25 16:00:43 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
	//member functions
		void	guardGate();
		void	attack(const std::string& target);

	//ORTHODOX FORMAT
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &original);
		ScavTrap	&operator=(const ScavTrap &original);
		~ScavTrap();
};

#endif