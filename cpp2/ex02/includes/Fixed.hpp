/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:27:17 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:45:29 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					num;
		static const int	fractional_bits = 8;
	public:
	//Member functions
		float	toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void)const;
		void setRawBits(int const raw);
		static Fixed	&min(Fixed &a, Fixed &b){
			return (a < b) ? a : b;
		}
		static Fixed const	&min(Fixed const &a, Fixed const &b){
			return (a < b) ? a : b;
		}
		static Fixed	&max(Fixed &a, Fixed &b){
			return (a > b) ? a : b;
		}
		static Fixed const	&max(Fixed const &a, Fixed const &b) {
			return (a > b) ? a : b;
		}
	//Constructors
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const &original);
	//Destructor
		~Fixed();
	//Copy assignment operator
		Fixed	&operator=(Fixed const &original);
	//Comparison operators
		bool	operator>(Fixed const &compare) const;
		bool	operator<(Fixed const &compare) const;
		bool	operator==(Fixed const &compare) const;
		bool	operator>=(Fixed const &compare) const;
		bool	operator<=(Fixed const &compare) const;
		bool	operator!=(Fixed const &compare) const;
	//Increment decrement operator
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
	//Arithmetic operators
		Fixed 	operator+(Fixed const &arg);
		Fixed	operator-(Fixed const &arg);
		Fixed	operator*(Fixed const &arg);
		Fixed	operator/(Fixed const &arg);
};

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original);




#endif