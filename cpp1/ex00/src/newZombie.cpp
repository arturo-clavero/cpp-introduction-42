/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:25:37 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:12:46 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*local_zombie;

	try {
		local_zombie = new Zombie(name);
	} catch(std::exception &e) {
		std::cout<<"Error: "<<e.what()<<"\n";
	}
	return (local_zombie);	
}