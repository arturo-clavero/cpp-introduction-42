/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:22:51 by arturo            #+#    #+#             */
/*   Updated: 2024/07/02 16:51:56 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//MEMBER FTS
void	Dog::makeSound()	const{
	std::cout<<"Bark bark, wook woof, guau guau\n";
}

//ORTHODOX FORMAT
Dog::Dog() {
	std::cout<<"Dog default constructor called\n";
	type = "Dog";
	localBrain = new Brain();
}

Dog::Dog(Dog const &original) : Animal(original){
	std::cout<<"Dog copy constructor called\n";
	type = original.type;
	localBrain = new Brain(*original.localBrain);
}

Dog	&Dog::operator=(Dog const &original) {
	std::cout<<"Dog copy assignment operator called\n";
	Animal::operator=(original);
	type = original.type;
	delete localBrain;
	localBrain = new Brain(*original.localBrain);
	return *this;
}

Dog::~Dog() {
	std::cout<<"Dog destructor called\n";
	delete localBrain;
}

