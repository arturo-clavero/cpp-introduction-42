/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:17:51 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:29:08 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	total = 4;
	std::string name= "rand guy";
	std::cout<<"Will call zombieHorde with N value of "<<total<<" and name "<<name<<":\n\n";
	Zombie	*local_zombies = zombieHorde(total, name);
	std::cout<<"\nWill call announce member ft, iterating from the pointer pointing to the first Zombie\n\n";
	for (int i = 0; i < total; i++)
		local_zombies[i].announce();
	std::cout<<"\nWill delete the array of zombies:\n\n";
	delete[] local_zombies;
}