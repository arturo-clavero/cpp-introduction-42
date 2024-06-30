/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:16:01 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 21:22:36 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

float	Fixed::toFloat(void) const{
	return (float)(num) / (1 << fractional_bits);
}

int	Fixed::toInt(void) const{
	return (int)(num >> fractional_bits);
}

int	Fixed::getRawBits(void)const{
	return (num);
}

void Fixed::setRawBits(int const raw){
	num = raw;
}

Fixed::Fixed(){
	num = 0;
	std::cout<<"Default constructor called\n";
}
		
Fixed::Fixed(int const num){
	std::cout<<"Int constructor called\n";
	this->num = num << fractional_bits;
}
		
Fixed::Fixed(float const num){
	std::cout<<"Float constructor called\n";
	this->num = (int)(num * (1 << fractional_bits));
}
		
Fixed::Fixed(Fixed const &original){
	std::cout<<"Copy constructor called\n";
	num = original.getRawBits();
}
		
Fixed	&Fixed::operator=(Fixed const &original){
	std::cout<<"Copy assignment operator called\n";
	num = original.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called\n";
}

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original){
	cout_param<<original.toFloat();
	return cout_param;		
}