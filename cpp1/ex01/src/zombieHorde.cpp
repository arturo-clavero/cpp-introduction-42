/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:47:25 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 15:52:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie	*local_zombies = new Zombie[n];
	
	for (int i = 0; i < n; i++)
		local_zombies[i].set_name(name);
	return (local_zombies);
}