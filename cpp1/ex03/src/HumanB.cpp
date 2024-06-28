/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:56:33 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:16:25 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str_name) : name(str_name)
{}

void	HumanB::attack(void)
{
	std::cout<<name<<" attacks with their "<<weapon->getType()<<"\n";
}

void	HumanB::setWeapon(Weapon &local_weapon)
{
	weapon = &local_weapon;
}
