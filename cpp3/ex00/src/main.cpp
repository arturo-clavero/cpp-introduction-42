/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:31 by arturo            #+#    #+#             */
/*   Updated: 2024/07/02 20:05:45 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	testConstructionDestruction()
{
	std::cout<<"\n.......................................\nTESTING SIMPLE CONSTRUTION AND DESTRUCTION\n";
	std::cout<<"\n\t 1. Initialize object of class ClapTrap\n";
	ClapTrap claptrap;
	std::cout<<"\n\t 1. Initialize object of class ClapTrap with name 'Jerry'\n";
	ClapTrap claptrapJerry("Jerry");
	std::cout<<"\n\t 2. Automatic destruction of both objects\n";
}

void	testCopyConstructor()
{
	std::cout<<"\n.......................................\nTESTING COPY CONSTRUCTOR\n";
	std::cout<<"\n\t 1. Initialize object of class ClapTrap with name 'Jerry'\n";
	ClapTrap claptrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class ClapTrap with previous object\n";
	ClapTrap claptrap(claptrapJerry);
	std::cout<<"\n\t 2. Let's print their details and check that they have the same name\n";
	claptrapJerry.printStats();
	claptrap.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testCopyAssignmentOperator()
{
	std::cout<<"\n.......................................\nTESTING COPY ASSIGNMENT OPERATOR\n";
	std::cout<<"\n\t 1. Initialize object of class ClapTrap with name 'Jerry'\n";
	ClapTrap claptrapJerry("Jerry");
	std::cout<<"\n\t 1. Initialize object of class ClapTrap with name 'Henry'\n";
	ClapTrap claptrapHenry("Henry");
	std::cout<<"\n\t 2. Let's print their details and check that they have different names\n";
	claptrapJerry.printStats();
	claptrapHenry.printStats();
	std::cout<<"\n\t Now we will let Henry equal to Jerry clap trap\n";
	claptrapHenry = claptrapJerry;
	std::cout<<"\n\t 2. Let's print their details again and check if they still have different names\n";
	claptrapJerry.printStats();
	claptrapHenry.printStats();
	std::cout<<"\n\t 3. Automatic destruction of both objects\n";
}

void	testMemberFts()
{
	std::cout<<"\n.......................................\nTESTING MEMBER FUNCTIONS\n";
	ClapTrap	Red("red team");
	ClapTrap	Blue("blue team");
	
	Red.attack("blue team");
	Blue.takeDamage(2);
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