/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:56:33 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:02:21 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string strName) : name(strName)
{}

void	HumanB::attack(void)
{
	std::cout<<name<<" attacks with their "<<weapon->getType()<<"\n";
}

void	HumanB::setWeapon(Weapon &localWeapon)
{
	weapon = &localWeapon;
}
