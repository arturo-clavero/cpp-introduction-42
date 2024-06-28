/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:56:25 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:07:40 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str_name, Weapon &local_weapon) : name(str_name), weapon(local_weapon)
{}

void	HumanA::attack(void)
{
	std::cout<<name<<" attacks with their "<<weapon.getType()<<"\n";
}