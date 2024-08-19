/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/20 05:36:50 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(void){
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(0);
	vec.push_back(7);
	vec.push_back(9);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(8);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(10);
	vec.push_back(12);
	std::vector<std::vector<int> > array;
	array.push_back(vec);
	std::cout<<"STARTING ARRAY :\n";
	print_2d_array(array);
	std::vector<std::vector<std::vector<int> > > pairs = make_pairs<std::vector<std::vector<int> > >(array);
	std::cout<<"\nPAIRS : \n";
	print_3d_array(pairs);
	//print_single(pairs[0][0]);
}

// template <typename Container>
// struct ContainerTraits;

// // Specialization for std::vector
// template <typename T>
// struct ContainerTraits<std::vector<T> > {
//     typedef std::vector<std::vector<T> > array;
// };

// // Specialization for std::deque
// template <typename T>
// struct ContainerTraits<std::deque<T> > {
//     typedef std::deque<std::deque<T> > array;
// };