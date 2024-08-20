/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 02:19:28 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
Container	ford_algo(typename Type<Container>::pair input){
	(void)input;
	std::cout<<"hey!\n";
	Container randomshit(3);
	return randomshit;
}

template <typename Container>
Container	ford_algo(Container input){
	std::cout<<"First\n";
	typename Type<Container>::pair false_pairs = make_null_pair(input);
	ford_algo<Container>(false_pairs);
	return input;
}

int main(void){
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	ford_algo<vector>(vec);
}

