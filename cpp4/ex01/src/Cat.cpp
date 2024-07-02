/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:20:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/02 16:51:26 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//MEMBER FTS
void	Cat::makeSound()const{
	std::cout<<"mew miaaaaaeeeewwwwwwwwwwwwww\n";
}

//ORTHODOX FORMAT
Cat::Cat() {
	std::cout<<"Cat default constructor called\n";
	type = "Cat";
	localBrain = new Brain();
}

Cat::Cat(Cat const &original) : Animal(original){
	std::cout<<"Cat copy constructor called\n";
	type = original.type;
	localBrain = new Brain(*original.localBrain);
}

Cat	&Cat::operator=(Cat const &original) {
	std::cout<<"Cat copy assignment operator called\n";
	Animal::operator=(original);
	type = original.type;
	delete localBrain;
	localBrain = new Brain(*original.localBrain);
	return *this;
}

Cat::~Cat() {
	std::cout<<"Cat destructor called\n";
	delete localBrain;
}

