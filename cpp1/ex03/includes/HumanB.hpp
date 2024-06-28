/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:57:04 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:10:06 by arturo           ###   ########.fr       */
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
		HumanB(std::string str_name);
		void	attack(void);
		void	setWeapon(Weapon &local_weapon);
};


# endif