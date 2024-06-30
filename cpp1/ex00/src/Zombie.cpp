/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:45 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:12:24 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{
	std::cout<<"Default onstructor called for class 'Zombie'\n";
}

Zombie::Zombie(std::string str)
{
	std::cout<<"Constructor with params called for class 'Zombie'\n";
	name = str;
}

Zombie::~Zombie(void)
{
	std::cout<<"Destructor called for class 'Zombie' named '"<<name<<"'\n";
}