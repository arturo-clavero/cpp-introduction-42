/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:37:27 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:04:41 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
	//member functions
		void	highFivesGuys(void);
		void	attack(const std::string& target);
		void	printStats();
	//ORTHODOX FORMAT
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &original);
		FragTrap	&operator=(FragTrap const &original);
		~FragTrap();
};

# endif