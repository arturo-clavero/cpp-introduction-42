/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/18 20:07:29 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(void){
	std::vector<int> vec, large, small;
	for (int i = 0; i < 11; i ++)
		vec.push_back(i + 1);
	std::vector<std::vector<int> > vector_pairs, large_small;
	vector_pairs = make_pairs<std::vector<std::vector<int> > >(vec);
	std::cout<<"PAIRS:\n";
	print_array(vector_pairs);
	large_small = compare_and_divide_pairs(vector_pairs);
	std::cout<<"\nLARGE\n";
	print_single(large_small[LARGE]);
	std::cout<<"\nSMALL\n";
	print_single(large_small[SMALL]);
}