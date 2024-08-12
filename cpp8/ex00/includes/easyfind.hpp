/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:17:00 by arturo            #+#    #+#             */
/*   Updated: 2024/08/10 18:21:18 by artclave         ###   ########.fr       */
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

typename T::iterator	easyfind(T &container, int const toFind){
	typename T::iterator result = std::find(container.begin(), container.end(), toFind);
	if (result == container.end())
		throw std::out_of_range("Element not found\n");
	return result;
}

#endif