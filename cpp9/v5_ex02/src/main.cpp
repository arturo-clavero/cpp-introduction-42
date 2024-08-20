/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 04:10:09 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// template <typename Container>
// void	reorder_large_elements_first(Container &input){
// 	std::cout<<"Determine large elements"
// 	int temp;
// 	for (int i = 0; i < static_cast<int>(input.size()); i++)
// 	{
// 		if (input[i].first.first < input[i].first.second)
// 		{
// 			temp = input[i].first.first;
// 			input[i].first.first = input[i].first.second;
// 			input[i].first.second = temp;
// 		}
// 	}
// }

template <typename Container>
Container	ford_algo(Container &input){
	typename Type<Container>::pair pairs;
	pair_elements(input, pairs);
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

