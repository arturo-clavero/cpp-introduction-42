/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SavTrap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:52 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:47:41 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVTRAP_HPP
# define SAVTRAP_HPP

#include "ClapTrap.hpp"

class	SavTrap : public ClapTrap
{
	public:
	//member functions
		void	guardGate();
	//ORTHODOX FORMAT
		SavTrap();
		SavTrap(const std::string &name);
		SavTrap(const SavTrap &original);
		SavTrap	&operator=(const SavTrap &original);
		~SavTrap();
};

#endif