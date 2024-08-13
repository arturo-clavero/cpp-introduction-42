/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:10:28 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 23:16:49 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av){
	unsigned long long time[2];
	if (ac < 2)
		PmergeMe<std::vector<int> >::error("not enough args\n");
	PmergeMe<std::vector<int> >original(av);
	std::cout<<"Input : "<<original.getContainer();
	time[0] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	PmergeMe<std::vector<int> >vec(av);
	vec.ford_algo();
	std::cout<<"Result : "<<vec.getContainer();
	time[0] -= static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;

	time[1] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	PmergeMe<std::list<int> >lst(av);
	lst.ford_algo();
	time[1] -= static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	std::cout<<"Time to process a range of "<<vec.getSize()<<" elements with std::list<int> : "<<time[0]<<" us\n";
	std::cout<<"Time to process a range of "<<lst.getSize()<<" elements with std::vector<int> : "<<time[1]<<" us\n";
}
