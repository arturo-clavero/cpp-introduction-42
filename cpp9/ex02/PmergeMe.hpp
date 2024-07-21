/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:05:25 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 17:22:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

template <typename T>
class PmergeMe {
	private:
		typedef T container;
		typedef &T	divide(int type, T input){
			int odd = input.size() % 2;
			T sub;
			typename T::iterator it = input.begin();
			for (int i = 0; i <  type * (static_cast<int>(input.size() / 2) + odd); i++)
				it++;
			for (int i = 0; i < static_cast<int>(input.size()) / 2 + (type * odd); i++){
				sub.push_back(*it);
				it++;
			}
			return sub;
		};
		void	sort();
		void	merge();
	public:
	//orthodox
		PmergeMe(){
			std::cout<<"Default constructor called for PmergeMe\n";
		};
		PmergeMe(char **av){
			std::cout<<"Constructor called for PmergeMe with string array\n";
			for (int i = 1; av[i]; i++){
				std::string str = av[i];
				int len = str.size();
				for (int j = 0; j < len; j++){		
					while (av[i][j] == ' ')
						j++;
					int num = atoi(&av[i][j]);
					container.push_back(num);
					if (av[i][j] == '+' || av[i][j] == '-')
						j++;
					if (num != 0)
					j += log10(abs(num));
					else
						j++;
				}
			}
		};
		PmergeMe(T container){
			std::cout<<"Constructor called for PmergeMe with container\n";		
			this->container = container;
		};
		PmergeMe(const PmergeMe &original){
			std::cout<<"Copy constructor called for PmergeMe\n";
			container = original->container;
		};
		PmergeMe	&operator=(const PmergeMe &original){
			std::cout<<"Copy assignment operator called for PmergeMe\n";
			container = original->container;
			return *this;
		};
	//MEMBER FTS
		void	print_container(std::string str = "list: "){
			std::cout<<str;
			typename T::iterator it = this->container.begin();
			while (it != this->container.end()){
				std::cout<<*it<<" ";
				it++;
			}
			std::cout<<"\n";
		};
};

template <>
void PmergeMe<std::list<int> >::sort() {
	container.sort();
}

template <>
void PmergeMe<std::list<int> >::merge() {
	container.merge();
}

void PmergeMe<std::vector<int> >::sort() {
	std::vector<int> result;
	std::vector<int>::iterator it;
	while (!container.empty()){
		it = std::min_element(container.begin(), container.end());
		result.push_back(*it);
		container.erase(it);
	}
	container = result;
}

template <>
void PmergeMe<std::vector<int> >::merge(std::vector<int> vec_b) {
	std::vector<int> result;
	std::merge(.begin(), container.end(), container.begin(), vec_b.end(), std::back_inserter(result));
	container = result;
}

#endif