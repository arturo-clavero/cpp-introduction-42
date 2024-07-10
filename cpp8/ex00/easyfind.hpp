/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:17:00 by arturo            #+#    #+#             */
/*   Updated: 2024/07/11 03:28:03 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

/*Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.e.*/

template <typename T>

void	easyfind(T container, int toFind){
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw std::out_of_range("Element not found\n");
	else
		std::cout<<"FOUND\n\n";
}

#endif