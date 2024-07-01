/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 17:10:58 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SavTrap.hpp"

int	main(void)
{
	SavTrap	Red("red team");
	SavTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
	Red.guardGate();
	Red.printStats();
	Blue.printStats();
	Blue.beRepaired(5);
	Blue.printStats();
}