/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:19:26 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 17:38:38 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

template<typename T>
void	test(std::string type){
	std::cout<<"TEST OF DATA TYPE:"<<type<<"\n\n";
	Array<T> a(5);
	for (int i = 0; i < 5; i++){
		a[i] = static_cast<T>(i) + static_cast<T>(70.5);
	}
	std::cout<<"Printing original array:\n";
	for (int i = 0; i < 5; i++){
		std::cout<<a[i]<<"\n";
	}
	std::cout<<"\nTesting to access array out of bounds..\n";
	try {
	std::cout<<a[5];}
	catch(std::exception &e){
		std::cout<<e.what()<<"\n";
	}
	std::cout<<"\nTesting size() member ft...\n";
	std::cout<<"size equals -> "<<a.size()<<"\n";
	std::cout<<"\nDeleting all arrays...\n";
}

int	main(void){
	test<int>(" ints");
	test<double>(" doubles");
	test<float>(" floats");
	test<char>(" char");
}