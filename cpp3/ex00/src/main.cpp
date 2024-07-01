/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:51:41 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Red("red team");
	ClapTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
	Red.printStats();
	Blue.printStats();
	Blue.beRepaired(5);
	Blue.printStats();
}