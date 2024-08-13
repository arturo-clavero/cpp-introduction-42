/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:10:28 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 11:15:14 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void	test_split(){
	std::vector<int> container, max, min;
	for (int i = 0; i < 13; i++){
		container.push_back(i);
	}
	std::cout<<"input: "<<container;
	split<std::vector<int> >(container, max, min);
	std::cout<<"MIN: "<<min;
	std::cout<<"MAX: "<<max;
	std::cout<<"\n";
}

int	main(int ac, char **av){
	if (ac < 2)
	{
		std::cerr<<"not enought args\n";
		exit(2);
	}
	std::vector<int> max;
	std::vector<int> min = init(av);
	max.push_back(12);
	// for (int i = 0; i < 5; i++){
	// 	min.push_back(10 - i);
	// }
	std::cout<<"before max: "<<max;
	std::cout<<"before min: "<<min;
	binary_sort<std::vector<int> >(max, min);
	std::cout<<"after max: "<<max;
}