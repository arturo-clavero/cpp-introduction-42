/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:29:26 by arturo            #+#    #+#             */
/*   Updated: 2024/07/11 03:14:21 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

void	testVectors(){
	std::vector<int> numbers(4, 10);
	int		toFind = 1;
	try {
	easyfind(numbers, toFind);
	std::cout<<"number "<<toFind<<" found\n";}
	catch(std::exception &e){
		std::cout<<"error: "<<e.what();
	}
}
/*
void	testArrays(){
	std::array<int, 5> numbers = {1, 2, 3, 4, 5};
	int		toFind = 5;
	try {
	auto result = easyfind(numbers, toFind);
	std::cout<<"number "<<toFind<<" found at ..pointer>"<<*result<<"\n";}
	catch(std::string errorType){
		std::cout<<"error: "<<errorType<<"\n";
	}
}*/

int	main(void){
	testVectors();
	//vectors  deque list 
}