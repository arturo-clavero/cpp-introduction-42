/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:17:51 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 15:48:25 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	total = 4;
	Zombie	*local_zombies = zombieHorde(total, "rand guy");
	for (int i = 0; i < total; i++)
		local_zombies[i].announce();
	delete[] local_zombies;
}