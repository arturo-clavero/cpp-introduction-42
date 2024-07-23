/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:22:51 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 18:07:21 by arturo           ###   ########.fr       */
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
}

Dog::Dog(const Dog &original) : Animal(original){
	std::cout<<"Dog copy constructor called\n";
	type = original.type;
}

Dog	&Dog::operator=(const Dog &original) {
	std::cout<<"Dog copy assignment operator called\n";
	Animal::operator=(original);
	type = original.type;
	return *this;
}

Dog::~Dog() {
	std::cout<<"Dog destructor called\n";
}

