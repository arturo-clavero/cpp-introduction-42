/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:20:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 18:07:05 by arturo           ###   ########.fr       */
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

Cat::Cat(const Cat &original) : Animal(original){
	std::cout<<"Cat copy constructor called\n";
	type = original.type;
}

Cat	&Cat::operator=(const Cat &original) {
	std::cout<<"Cat copy assignment operator called\n";
	Animal::operator=(original);
	type = original.type;
	return *this;
}

Cat::~Cat() {
	std::cout<<"Cat destructor called\n";
}

