/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:59:12 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:02:19 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

const std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string str)
{
	type = str;
}

Weapon::Weapon()
{
    type = "Undefined";
}
		
Weapon::Weapon(std::string str)
{
	type = str;
}