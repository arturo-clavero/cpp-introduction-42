/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:45 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 15:24:43 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string str)
{
	name = str;
}

Zombie::~Zombie(void)
{
	std::cout<<"Destroying zombie "<<name<<"\n";
}