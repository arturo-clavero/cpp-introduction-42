/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:57:04 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:01:04 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		std::string	name;
		Weapon		*weapon;
		HumanB(std::string strName);
		void	attack(void);
		void	setWeapon(Weapon &localWeapon);
};


# endif