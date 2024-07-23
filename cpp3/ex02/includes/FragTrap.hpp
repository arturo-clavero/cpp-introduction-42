/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:37:27 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 17:57:16 by arturo           ###   ########.fr       */
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
	//ORTHODOX FORMAT
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &original);
		FragTrap	&operator=(const FragTrap &original);
		~FragTrap();
};

# endif