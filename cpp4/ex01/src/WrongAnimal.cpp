/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:25:03 by arturo            #+#    #+#             */
/*   Updated: 2024/07/24 15:55:04 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound()	const{
	std::cout<<"I am defenitely not a cat and I clearly dont understand polymorphysm, can't even spell it\n";
}
		
std::string	WrongAnimal::getType() const {
	return type;
}

//ORTHODOX FORMAT
WrongAnimal::WrongAnimal() {
	std::cout<<"WrongAnimal default constructor called\n";
	type = "";
}

WrongAnimal::WrongAnimal(const std::string &type) {
	std::cout<<"WrongAnimal constructor with params called\n";
	this->type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal const &original) {
	std::cout<<"WrongAnimal copy constructor called\n";
	type = original.type;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &original) {
	std::cout<<"WrongAnimal copy assignment operator called\n";
	type = original.type;
	return *this;
}
		
WrongAnimal::~WrongAnimal() {
	std::cout<<"WrongAnimal (~"<<type<< "~) destructor called\n";
}
