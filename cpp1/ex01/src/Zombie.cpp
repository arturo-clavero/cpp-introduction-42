/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:43:14 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 15:45:20 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string str)
{
	name = str;
}

Zombie::~Zombie(void)
{
	std::cout<<"Destroying zombie "<<name<<"\n";
}