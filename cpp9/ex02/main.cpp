/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:09:52 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 03:23:25 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av){
	unsigned long long time[2];
	if (ac < 2){
		std::cerr<<"Not enough arguments\n";
		return 2;
	}
	try {
		std::list<int> store_original = init_data(av);
		time[LIST] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		std::list<int> list = init_data(av);
		algo(list);
		time[LIST] -= static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		std::vector<int> vector = init_data(av);
		algo(vector);
		time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		print("before: ", store_original);
		print("after: ", list);
		//print("after: ", vector);
		std::cout<<"Time to process a range of "<<list.size()<<" elements with std::list<int> : "<<time[LIST]<<" us\n";
		std::cout<<"Time to process a range of "<<vector.size()<<" elements with std::vector<int> : "<<time[VECTOR]<<" us\n";
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}