/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:17:04 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:55:22 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType() const{
	return type;
}
	
//ORTHODOX FORMAT
Animal::Animal() {
	std::cout<<"Animal default constructor called\n";
	type = "";
}

Animal::Animal(std::string type) {
	std::cout<<"Animal constructor with params called\n";
	this->type = type;
}

Animal::Animal(Animal const &original) {
	std::cout<<"Animal copy constructor called\n";
	type = original.type;
}

Animal	&Animal::operator=(Animal const &original) {
	std::cout<<"Animal copy assignment operator called\n";
	type = original.type;
	return *this;
}

Animal::~Animal() {
	std::cout<<"Animal (~"<<type<< "~) destructor called\n";
}
