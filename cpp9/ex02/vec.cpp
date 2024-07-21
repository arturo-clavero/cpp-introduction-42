/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:16 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 16:52:28 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:14:08 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 15:24:14 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "PmergeMe.hpp"
#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <ctime>
#include <limits>
#include <algorithm> 

#define FRONT 0
# define BACK 1
# define FALSE 0
# define TRUE 1
# define LIST 0
# define VECTOR 1

void	print_vector(std::vector<int> vector, std::string str = "vector: "){
	std::cout<<str;
	std::vector<int>::iterator it = vector.begin();
	while (it != vector.end()){
		std::cout<<*it<<" ";
		it++;
	}
	std::cout<<"\n";
}

std::vector<int>	divide(std::vector<int> vector, int section){
	int odd = vector.size() % 2;
	std::vector<int> subvector;
	std::vector<int>::iterator it = vector.begin();
	for (int i = 0; i <  section * (static_cast<int>(vector.size() / 2) + odd); i++)
		it++;
	for (int i = 0; i < static_cast<int>(vector.size()) / 2 + (section * odd); i++){
		subvector.push_back(*it);
		it++;
	}
	return subvector;
}

std::vector<int>	sort_vector(std::vector<int> vector){
	std::vector<int> result;
	std::vector<int>::iterator it;
	while (!vector.empty()){
		it = std::min_element(vector.begin(), vector.end());
		result.push_back(*it);
		vector.erase(it);
	}
	return result;
}

std::vector<int>	merge_vector(std::vector<int> vec_a, std::vector<int> vec_b){
	std::vector<int> result;
	std::merge(vec_a.begin(), vec_a.end(), vec_b.begin(), vec_b.end(), std::back_inserter(result));
	return result;
}

std::vector<int>	vector_algo(std::vector<int> vector){
	if (vector.size() < 3){
		vector = sort_vector(vector);
		return (vector);
	}
	std::vector<int> vector_a = vector_algo(divide(vector, FRONT));
	vector_a = sort_vector(vector_a);
	std::vector<int> vector_b = vector_algo(divide(vector, BACK));
	vector_b = sort_vector(vector_b);
	vector_b = merge_vector(vector_a, vector_b);
	return (vector_b);
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

std::vector<int>	init_vector(char **av){
	std::vector<int> vector;
	for (int i = 1; av[i]; i++){
		std::string str = av[i];
		int len = str.size();
		for (int j = 0; j < len; j++){		
			while (av[i][j] == ' ')
				j++;
			int num = atoi(&av[i][j]);
			vector.push_back(num);
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			if (num != 0)
				j += log10(abs(num));
			else
				j++;
		}
	}
	return vector;
}

int	main(int ac, char **av){
	if (ac < 2){
		std::cerr<<"Not enough arguments\n";
		return 2;
	}
	unsigned long long	start[2];
	unsigned long long	time[2];
	start[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC;
	check_valid_arguments(av);
	std::vector<int> vector_input = init_vector(av);
	std::vector<int> vector_output = vector_algo(vector_input);
	time[VECTOR] = static_cast<unsigned long long>(clock()) * 1000000ULL / CLOCKS_PER_SEC - start[VECTOR];
	//
	std::cout<<"Time to process a range of "<<vector_input.size()<<" elements with std::vector<int> : "<<time[VECTOR]<<" us\n";
	print_vector(vector_input, "Before: ");
	print_vector(vector_output, "After:  ");
}