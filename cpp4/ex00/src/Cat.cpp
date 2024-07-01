/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:20:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:22:45 by arturo           ###   ########.fr       */
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
}

Cat::Cat(Cat const &original) : Animal(original){
	std::cout<<"Cat copy constructor called\n";
	type = original.type;
}

Cat	&Cat::operator=(Cat const &original) {
	std::cout<<"Cat copy assignment operator called\n";
	Animal::operator=(original);
	type = original.type;
	return *this;
}

Cat::~Cat() {
	std::cout<<"Cat destructor called\n";
}

