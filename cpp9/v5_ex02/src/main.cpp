/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 15:02:55 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"





#include <cstdlib>   // for rand() and srand()
#include <ctime>


int main(int ac, char **av){
	// std::vector<int> vec;
	// std::vector<int> og;
	// std::srand(std::time(0));
	// for (int i = 0; i < 11; i ++)
	// 	vec.push_back(std::rand() % 101);
	// og = vec;
	// PmergeMe::ford_algo(vec);

	// std::cout<<"\n\n\nINPUT : ";
	// PmergeMe::print_container(og);
	// std::cout<<"OUTPUT: ";
	// PmergeMe::print_container(vec);
	if (ac < 2)
		PmergeMe::error("not enough args\n");
	std::vector<int> vec = PmergeMe::parsing<vector>(av);
	PmergeMe::ford_algo(vec);
}

