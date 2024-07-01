/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:02 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:16:01 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal("Animal hehe");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal("error animal");
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!*/
	j->makeSound();	
	meta->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	delete meta;
	delete j;
	delete i;	
	delete wrongAnimal;
	delete wrongCat;
}