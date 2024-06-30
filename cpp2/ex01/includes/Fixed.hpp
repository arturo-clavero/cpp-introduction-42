/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:15:20 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 21:17:33 by arturo           ###   ########.fr       */
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
		float	toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void)const;
		void setRawBits(int const raw);
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const &original);
		Fixed	&operator=(Fixed const &original);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original);

#endif