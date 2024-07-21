/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:09:52 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 20:01:55 by artclave         ###   ########.fr       */
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
		PmergeMe<std::list<int> > store_original(av);
		time[LIST] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		PmergeMe<std::list<int> > list(av);
		list.algo();
		time[LIST] -= static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		PmergeMe<std::vector<int> > vector(av);
		vector.algo();
		time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
		store_original.print("before: ");
		list.print("after: ");
		std::cout<<"Time to process a range of "<<list.size()<<" elements with std::list<int> : "<<time[LIST]<<" us\n";
		std::cout<<"Time to process a range of "<<vector.size()<<" elements with std::vector<int> : "<<time[VECTOR]<<" us\n";
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}