/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:48:47 by arturo            #+#    #+#             */
/*   Updated: 2024/08/09 22:00:01 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
template<typename T>

class Array{
	private:
		T *array;
		int	len;
	
	public:
		Array();
		Array(unsigned int const n);
		Array(Array const &original);
		Array	&operator=(Array const &original);
		T&	operator[](int index) const;
		int	size() const;
		~Array();
};

#include "Array.tpp"

#endif