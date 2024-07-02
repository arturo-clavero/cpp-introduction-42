/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:02 by arturo            #+#    #+#             */
/*   Updated: 2024/07/02 18:14:59 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void	testConstructionDestruction()
{
	std::cout<<"////////////////////////////////////////////////////////\nTest construction and destruction Cat object with Brain:\n\n";
	std::cout<<"\n\t 1. Initialize object\n";
	const	Cat i;
	std::cout<<"\n\t 2. Automatic destruction (out of scope)\n";
}

void	testConstructionDestructionWithAlloc()
{
	std::cout<<"////////////////////////////////////////////////////////\nTest construction and destruction allocating Dog object with Brain:\n\n";
	std::cout<<"\n\t 1. Initialize object\n";
	const Animal* j = new Dog();
	std::cout<<"\n\t 2. Delete object\n";
	delete j;
}

void	testCopyConstructor()
{
	std::cout<<"\n////////////////////////////////////////////////////////\nTest copy construction of Cat object with Brain:\n\n";
	std::cout<<"\n\t 1.Initialize first dog>\n";
	const	Dog	one;
	std::cout<<"\n\t 2.Initialize second dog with first one>\n";
	const	Dog	two(one);
	std::cout<<"\n\t 3.Automatic destruction of both Dogs\n";
}

void	testCopyConstructorWithAlloc()
{
	std::cout<<"////////////////////////////////////////////////////////\nTest copy construction of allocated Dog object with Brain:\n\n";
	std::cout<<"\n\t 1.Allocate one cat\n";
	Animal *oneCat = new Cat();
	std::cout<<"\n\t 2.Allocate another cat, using previous cat\n";
	Animal *anotherCat = new Cat(*static_cast<Cat*>(oneCat)); 
	std::cout<<"\n\t 3.Delete one cat>\n";
	delete oneCat;
	std::cout<<"\n\t 4.Delete another cat>\n";
	delete anotherCat;
}

void	testCopyAssignmentOperator()
{
	std::cout<<"\n////////////////////////////////////////////////////////\nTest copy assignment operator of Cat object with Brain:\n\n";
	std::cout<<"\n\t 1.Initialize first cat>\n";
	Cat	one;
	std::cout<<"\n\t 2.Initialize second cat>\n";
	Cat	two;
	std::cout<<"\n\t 3.Copying cats:\n";
	two = one;
	std::cout<<"\n\t 4.DAutomatic destruction of both Cats:\n";
}

void	testCopyAssignmentOperatorWithAlloc()
{
	std::cout<<"////////////////////////////////////////////////////////\nTest copy assignment operator of ALLOCATED Dog object with Brain:\n\n";
	std::cout<<"\n\t 1.Allocate first dog>\n";
	Animal	*firstDog = new Dog();
	std::cout<<"\n\t 2.Allocate second dog:\n";
	Animal *secondDog = new Dog();
	std::cout<<"\n\t 3.Copying dogs:\n";
	*static_cast<Dog*>(firstDog) = *static_cast<Dog*>(secondDog); //We use static cast to change from *Animal to *Dog and dereference back to Dog
	std::cout<<"\n\t 4.Deleting first dog:\n";
	delete	firstDog;
	std::cout<<"\n\t 5.Deleting second dog:\n";
	delete	secondDog;
}

void	proofNoneAbstractBaseClass()
{
	std::cout<<"For the final test we will check that we can create an instance of our base Animal class and call its member functions\n";
	std::cout<<"This proofs that our base class is not abstract at the moment (abstract classes can not be initialized)\n";
	std::cout<<"\n\t 1. Initialize base class object\n";
	Animal animal("random");
	std::cout<<"\n\t 2. Let's call some member fts\n";
	animal.makeSound();
	animal.getType();
	std::cout<<"\n\t 3. Automatic destruction\n";
}

int main()
{
	//testConstructionDestruction();
	//testConstructionDestructionWithAlloc();
	//testCopyConstructor();
	//testCopyConstructorWithAlloc();
	//testCopyAssignmentOperator();
	//testCopyAssignmentOperatorWithAlloc();
	proofNoneAbstractBaseClass();
	return (0);
}
	