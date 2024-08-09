/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:49 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 17:50:19 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void	printData(T data){
	std::cout<<data<<"\n";
}

template<typename T>
void	testing()
{
	int	length = 5;
	T	array[length];
	for (int i = 0; i < length; i++){
		array[i] = static_cast<T>(i + 78.2345678);
	}
	iter(array, length, printData<T>);
	std::cout<<"\n";
}

int	main(void){
	testing<char>();
	testing<int>();
	testing<double>();
	testing<char>();
}