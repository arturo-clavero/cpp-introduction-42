/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:55:01 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 17:17:40 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	&algo(PmergeMe &input){
	if (input.container.size() < 3){
		input.sort();
		return ;
	}
	PmergeMe sub_a(this->algo(this->divide(FRONT, input)));
	sub_a.sort();
	PmergeMe sub_b(this->algo(this->divide(BACK, input)));
	sub_b.sort();
	sub_b.merge(sub_a);
	this->container = sub_b->container;
}

int main(char **av, int ac){
	if (ac < 2){
		std::cerr<<"Not enough arguments\n";
		return 2;
	}
	check_valid_arguments(av);
	PmergeMe<std::list<int> > list(av);
	algo(list);
	list.print_container();
	/*
	unsigned long long	start[2];
	unsigned long long	time[2];
	start[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	std::vector<int> vector_input = init_vector(av);
	std::vector<int> vector_output = vector_algo(vector_input);
	time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC - start[VECTOR];
	//
	std::cout<<"Time to process a range of "<<vector_input.size()<<" elements with std::vector<int> : "<<time[VECTOR]<<" us\n";
	print_vector(vector_input, "Before: ");
	print_vector(vector_output, "After:  ");
*/
}