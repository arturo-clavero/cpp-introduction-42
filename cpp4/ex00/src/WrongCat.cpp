/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:27:26 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 18:10:24 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//MEMBER FTS
void	WrongCat::makeSound()const{
	std::cout<<"mew miaaaaaeeeewwwwwwwwwwwwww (WRONG)\n";
}

//ORTHODOX FORMAT
WrongCat::WrongCat() {
	std::cout<<"WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original){
	std::cout<<"WrongCat copy constructor called\n";
	type = original.type;
}

WrongCat	&WrongCat::operator=(const WrongCat &original) {
	std::cout<<"WrongCat copy assignment operator called\n";
	WrongAnimal::operator=(original);
	type = original.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout<<"WrongCat destructor called\n";
}

