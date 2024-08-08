/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:21 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 20:09:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>
void	swap(T & a, T & b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const &	min(T const & a, T const & b){
	if (a < b)
		return a;
	return b;
}

template<typename T>
T const &	max(T const & a, T const & b){
	if (a > b)
		return a;
	return b;
}

#endif