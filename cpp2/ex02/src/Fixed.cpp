/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:26:14 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:41:49 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

	//Member functions
float	Fixed::toFloat(void) const{
	return (float)(num) / (1 << fractional_bits);
}

int	Fixed::toInt(void) const{
	return (num >> fractional_bits);
}

int	Fixed::getRawBits(void)const{	
	return (num);
}

void Fixed::setRawBits(int const raw){
	num = raw;
}


	//Constructors
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

	//Destructor
Fixed::~Fixed(){
	std::cout<<"Destructor called\n";
}

	//Copy assignment operator
Fixed	&Fixed::operator=(Fixed const &original){
	std::cout<<"Copy assignment operator called\n";
	num = original.getRawBits();
	return *this;
}

	//Comparison operators
bool	Fixed::operator>(Fixed const &compare) const{		
	if (toFloat() > compare.toFloat())
		return	true;
	return	false;
}

bool	Fixed::operator<(Fixed const &compare) const{
	if (toFloat() < compare.toFloat())
		return	true;
	return	false;
}

bool	Fixed::operator==(Fixed const &compare) const{
	if ((toFloat() == compare.toFloat()))
		return	true;
	return	false;
}

bool	Fixed::operator>=(Fixed const &compare) const{
	if (*this == compare || *this > compare)
		return	true;
	return	false;
}

bool	Fixed::operator<=(Fixed const &compare) const{
	if (*this == compare || *this < compare)
		return	true;
	return	false;
}

bool	Fixed::operator!=(Fixed const &compare) const{
	if (*this == compare)
		return false;
	return	true;
}

	//Increment decrement operator
Fixed	&Fixed::operator++() { //returning obj by reference so that << ++a can work aka we can chain operations if we return the obj
    num += 1;// << fractional_bits;
	return *this;
}
		
Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	num += 1;// << fractional_bits;
	return temp;
}

Fixed	&Fixed::operator--() {
	num -= 1;// << fractional_bits;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	num -= 1;// << fractional_bits;
	return temp;
}

	//Arithmetic operators
Fixed 	Fixed::operator+(Fixed const &arg) {
	Fixed	result(toFloat() + arg.toFloat());
	return	(result); //have to return by VALUE because otherwise the obj is out of local scope....
}

Fixed	Fixed::operator-(Fixed const &arg) {
	Fixed	result(toFloat() - arg.toFloat());
	return	(result);
}

Fixed	Fixed::operator*(Fixed const &arg) {
	Fixed	result(toFloat() * arg.toFloat());
	return	(result);
}

Fixed	Fixed::operator/(Fixed const &arg) {
	Fixed	result(toFloat() / arg.toFloat());
	return	(result);
}

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original){
	cout_param<<original.toFloat();
	return cout_param;		
}
