/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:03:42 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 19:05:10 by arturo           ###   ########.fr       */
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
		int	getRawBits(void)const;
		void setRawBits(int const raw);
		Fixed();
		Fixed(Fixed const &original);
		Fixed	&operator=(Fixed const &original);
		~Fixed();
};

#endif