/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:49 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 15:54:39 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void	printData(T data){
	std::cout<<data<<"\n";
}

void	testingIntArray(){
	std::cout<<"\nprinting an array of 5 ints:\n";
	int	length = 5;
	int	array[length];
	for (int i = 0; i < length; i++){
		array[i] = i * 10;
	}
	iter(array, length, printData<int>);
}

void	testingDoubleArray(){
	std::cout<<"\nprinting an array of 5 doubles:\n";
	int	length = 5;
	double	array[length];
	for (int i = 0; i < length; i++){
		array[i] = static_cast<double>(i) + 1.1 * 7.7 / 3.3;
	}
	iter(array, length, printData<double>);
}

void	testingFloatArray(){
	std::cout<<"\nprinting an array of 5 floats:\n";
	int	length = 5;
	float	array[length];
	for (int i = 0; i < length; i++){
		array[i] = static_cast<float>(i) + 3.5 * 4.4 / 1.8975;
	}
	iter(array, length, printData<float>);
}

void	testingCharArray(){
	std::cout<<"\nprinting an array of 5 chars:\n";
	int	length = 5;
	char	array[length];
	for (int i = 0; i < length; i++){
		array[i] = static_cast<char>(i) + 78;
	}
	iter(array, length, printData<char>);
}

int	main(void){
	testingIntArray();
	testingDoubleArray();
	testingFloatArray();
	testingCharArray();
}