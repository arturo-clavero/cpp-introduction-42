/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 17:49:13 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Red("red team");
	FragTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
	Red.highFivesGuys();
	Red.printStats();
	Blue.printStats();
	Blue.beRepaired(5);
	Blue.printStats();
}