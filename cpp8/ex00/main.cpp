/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:29:26 by arturo            #+#    #+#             */
/*   Updated: 2024/07/11 18:29:50 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

template<typename T>

void	test(T &numbers, int toFind, std::string test){
	std::cout<<test;
	try {
	typename T::iterator itFound = easyfind(numbers, toFind);
	std::cout<<"number "<<toFind<<" found at "<<std::distance(numbers.begin(), itFound)<<"\n";}
	catch(std::exception &e){
		std::cout<<"error: "<<e.what();
	}
}

void	testingVectors(){
	std::vector<int> contVector(4, 10);
	test(contVector, 1, "\nTesting invalid element with vector container:\n");
	test(contVector, 10, "\nTesting valid element with vector container:\n");
}

void	testingDeques(){
	std::deque<int> contDeque(4, 10);
	test(contDeque, 1, "\nTesting invalid element with deque container:\n");
	test(contDeque, 10, "\nTesting valid element with deque container:\n");
}

void	testingLists(){
	std::list<int> contList(4, 10);
	test(contList, 1, "\nTesting invalid element with list container:\n");
	test(contList, 10, "\nTesting valid element with list container:\n");
}

int	main(void){
	testingVectors();
	testingDeques();
	testingLists();	
}