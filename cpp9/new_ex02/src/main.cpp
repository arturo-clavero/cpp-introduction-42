/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/19 01:40:12 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>   // for rand() and srand()
#include <ctime>  

int main(void){
	std::vector<int> vec;
	std::srand(std::time(0));
	for (int i = 0; i < 11; i ++)
		vec.push_back(std::rand() % 101);
	ford_johnson_algo<std::vector<std::vector<int> > >(vec);
}