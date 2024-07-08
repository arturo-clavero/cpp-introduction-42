/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:21 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 15:19:48 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>
void	swap(T a, T b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template<typename T>
T	max(T a, T b){
	if (a > b)
		return a;
	return b;
}





#endif