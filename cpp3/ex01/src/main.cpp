/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/02 20:10:01 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SavTrap.hpp"

void	testConstructionDestruction()
{
	std::cout<<"\n.......................................\nTESTING SIMPLE CONSTRUTION AND DESTRUCTION\n";
	std::cout<<"\n\t 1. Initialize object of class SavTrap\n";
	SavTrap savtrap;
	std::cout<<"\n\t 1. Initialize object of class SavTrap with name 'Jerry'\n";
	SavTrap savtrapJerry("Jerry");
	std::cout<<"\n\t 2. Automatic destruction of both objects\n";
}

void	testCopyConstructor()
{
	std::cout<<"\n.......................................\nTESTING COPY CONSTRUCTOR\n";
	std::cout<<"\n\t 1. Initialize object of class SavTrap with name 'Jerry'\n";
	SavTrap savtrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class SavTrap with previous object\n";
	SavTrap savtrap(savtrapJerry);
	std::cout<<"\n\t 2. Let's print their details and check that they have the same name\n";
	savtrapJerry.printStats();
	savtrap.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testCopyAssignmentOperator()
{
	std::cout<<"\n.......................................\nTESTING COPY ASSIGNMENT OPERATOR\n";
	std::cout<<"\n\t 1. Initialize object of class SavTrap with name 'Jerry'\n";
	SavTrap savtrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class SavTrap with name 'Henry'\n";
	SavTrap savtrapHenry("Henry");
	std::cout<<"\n\t 2. Let's print their details and check that they have different names\n";
	savtrapJerry.printStats();
	savtrapHenry.printStats();
	std::cout<<"\n\t Now we will let Henry equal to Jerry clap trap\n";
	savtrapHenry = savtrapJerry;
	std::cout<<"\n\t 2. Let's print their details again and check if they still have different names\n";
	savtrapJerry.printStats();
	savtrapHenry.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testMemberFts()
{
	std::cout<<"\n.......................................\nTESTING MEMBER FUNCTIONS\n";
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

int	main(void)
{
	testConstructionDestruction();
	testCopyConstructor();
	testCopyAssignmentOperator();
	testMemberFts();
}
