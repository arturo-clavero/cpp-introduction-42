/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:03:13 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 21:08:15 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBits(void)const {	
	std::cout<<"getRawBits member function called\n";
	return (num);
}

void Fixed::setRawBits(int const raw) {
	num = raw;
	std::cout<<"setRawBits member function called\n";
}
		
Fixed::Fixed() {
	num = 0;
	std::cout<<"Default constructor called\n";
}
		
Fixed::Fixed(Fixed &original) {
	std::cout<<"Copy constructor called\n";
	num = original.getRawBits();
}
		
Fixed	&Fixed::operator=(Fixed &original){
	std::cout<<"Copy assignment operator called\n";	
	num = original.getRawBits();
	return *this;
}
		
Fixed::~Fixed(){
	std::cout<<"Destructor called\n";
}