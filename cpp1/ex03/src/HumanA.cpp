/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:56:25 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:01:57 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string strName, Weapon &localWeapon) : name(strName), weapon(localWeapon)
{}

void	HumanA::attack(void)
{
	std::cout<<name<<" attacks with their "<<weapon.getType()<<"\n";
}