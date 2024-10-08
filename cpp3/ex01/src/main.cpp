/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/25 15:59:36 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	testConstructionDestruction()
{
	std::cout<<"\n.......................................\nTESTING SIMPLE CONSTRUTION AND DESTRUCTION\n";
	std::cout<<"\n\t 1. Initialize object of class ScavTrap\n";
	ScavTrap scavTrap;
	std::cout<<"\n\t 1. Initialize object of class ScavTrap with name 'Jerry'\n";
	ScavTrap scavtrapJerry("Jerry");
	std::cout<<"\n\t 2. Automatic destruction of both objects\n";
}

void	testCopyConstructor()
{
	std::cout<<"\n.......................................\nTESTING COPY CONSTRUCTOR\n";
	std::cout<<"\n\t 1. Initialize object of class ScavTrap with name 'Jerry'\n";
	ScavTrap scavtrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class ScavTrap with previous object\n";
	ScavTrap scavtrap(scavtrapJerry);
	std::cout<<"\n\t 2. Let's print their details and check that they have the same name\n";
	scavtrapJerry.printStats();
	scavtrap.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testCopyAssignmentOperator()
{
	std::cout<<"\n.......................................\nTESTING COPY ASSIGNMENT OPERATOR\n";
	std::cout<<"\n\t 1. Initialize object of class ScavTrap with name 'Jerry'\n";
	ScavTrap scavtrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class ScavTrap with name 'Henry'\n";
	ScavTrap scavtrapHenry("Henry");
	std::cout<<"\n\t 2. Let's print their details and check that they have different names\n";
	scavtrapJerry.printStats();
	scavtrapHenry.printStats();
	std::cout<<"\n\t Now we will let Henry equal to Jerry clap trap\n";
	scavtrapHenry = scavtrapJerry;
	std::cout<<"\n\t 2. Let's print their details again and check if they still have different names\n";
	scavtrapJerry.printStats();
	scavtrapHenry.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testMemberFts()
{
	std::cout<<"\n.......................................\nTESTING MEMBER FUNCTIONS\n";
	ScavTrap	Red("red team");
	ScavTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
	Red.guardGate();
	Red.printStats();
	Blue.printStats();
	Blue.beRepaired(5);
	Blue.printStats();
}

int	main(void)
{
	testConstructionDestruction();
	testCopyConstructor();
	testCopyAssignmentOperator();
	testMemberFts();
}
