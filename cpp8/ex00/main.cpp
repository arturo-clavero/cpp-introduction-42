/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:29:26 by arturo            #+#    #+#             */
/*   Updated: 2024/08/09 03:32:32 by artclave         ###   ########.fr       */
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

template<typename T>
void	createContainer(){
	T cont(4, 10);
	test<T>(cont, 1, "\nTesting invalid element:\n");
	test<T>(cont, 10, "\nTesting valid element:\n");
}

int	main(void){
	createContainer<std::vector<int> >();
	createContainer<std::deque<int> >();
	createContainer<std::list<int> >();
}