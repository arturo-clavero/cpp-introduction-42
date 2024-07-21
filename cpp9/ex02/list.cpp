/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:14:08 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 16:29:24 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "PmergeMe.hpp"
#include <iostream>
#include <list>
#include <cmath>
#include <ctime>

#define FRONT 0
# define BACK 1
# define FALSE 0
# define TRUE 1
# define LIST 0
# define VECTOR 1

void	print_list(std::list<int> list, std::string str = "list: "){
	std::cout<<str;
	std::list<int>::iterator it = list.begin();
	while (it != list.end()){
		std::cout<<*it<<" ";
		it++;
	}
	std::cout<<"\n";
}

std::list<int>	divide(std::list<int> list, int section){
	int odd = list.size() % 2;
	std::list<int> sublist;
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i <  section * (static_cast<int>(list.size() / 2) + odd); i++)
		it++;
	for (int i = 0; i < static_cast<int>(list.size()) / 2 + (section * odd); i++){
		sublist.push_back(*it);
		it++;
	}
	return sublist;
}

std::list<int>	list_algo(std::list<int> list){
	if (list.size() < 3){
		list.sort();
		return (list);
	}
	std::list<int> list_a = list_algo(divide(list, FRONT));
	list_a.sort();
	std::list<int> list_b = list_algo(divide(list, BACK));
	list_b.sort();
	list_b.merge(list_a);
	return (list_b);
}

void	check_valid_arguments(char **av){
	for (int i = 1; av[i]; i++){
		for (int j = 0; av[i][j];){
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if (av[i][j] && (av[i][j] == '+' || av[i][j] == '-'))
				j++;
			if (!av[i][j])
				continue ;
			if (!std::isdigit(av[i][j]))
			{
				std::cout<<"Invalid arguments\n";
				exit (2);
			}
			while (std::isdigit(av[i][j]))
				j++;
			if (av[i][j] && av[i][j] != ' '){
				std::cerr<<"Invalid arguments\n"<<i<<", "<<j<<"\n";
				exit (2);
			}
		}
	}
}

int	main(int ac, char **av){
	if (ac < 2){
		std::cerr<<"Not enough arguments\n";
		return 2;
	}
	unsigned long long	start[2];
	unsigned long long	time[2];
	start[LIST] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	check_valid_arguments(av);
	std::list<int> input = init_list(av);
	std::list<int> output = list_algo(input);
	time[LIST] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC - start[LIST];

	std::cout<<"Time to process a range of "<<input.size()<<" elements with std::list<int> : "<<time[LIST]<<" us\n";
	//std::cout<<"Time to process a range of "<<input.size()<<" elements with std::vector<int> : "<<time[VECTOR]<<" us\n";
	print_list(input, "Before: ");
	print_list(output, "After:  ");
	
}