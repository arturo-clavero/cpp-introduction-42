/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:23 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 20:27:28 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

#define FRONT 0
# define BACK 1
# define FALSE 0
# define TRUE 1
# define LIST 0
# define VECTOR 1

template <typename T>
class PmergeMe{
	private:
		T container;

	public:
	//ORTHODOX
		PmergeMe(){
		//	std::cout<<"Default constructor called\n";
		}
		PmergeMe(char **av){
			//std::cout<<"Constructor with string array called\n";
			for (int i = 1; av[i]; i++){
				for (int j = 0; av[i][j];){
					while (av[i][j] && av[i][j] == ' ')
						j++;
					if (av[i][j] && (av[i][j] == '+' || av[i][j] == '-'))
						j++;
					if (!av[i][j])
						continue ;
					if (!std::isdigit(av[i][j]))
						throw std::runtime_error("Invalid arguments\n");
					while (std::isdigit(av[i][j]))
						j++;
					if (av[i][j] && av[i][j] != ' ')
						throw std::runtime_error("Invalid args\n");
				}
			}
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
		}
		PmergeMe(T container){
		//	std::cout<<"Constructor called with container\n";
			this->container = container;
		}
		PmergeMe(PmergeMe const &og){
		//	std::cout<<"Copy constructor called\n";
			container = og.container;
		}
		PmergeMe	&operator=(PmergeMe const &og){
		//	std::cout<<"Copy assignment operator called\n";
			container = og.container;
			return *this;
		}
		~PmergeMe(){
		//	std::cout<<"Default destructor called\n";
		}
	//MEMBER FTS:
		T	get_container(){
			return container;
		}
		void	set_container(T container){
			this->container = container;
		}
		int	size(){
			return static_cast<int>(container.size());
		}
		void	sort();
		void	merge(T other);
		void	divide(int section){
			int odd = this->size() % 2;
			typename T::iterator it = this->container.begin();
			T	sub;
			for (int i = 0; i < section * (this->size() / 2 + odd); i++)
				it++;
			for (int i = 0; i < this->size() / 2 + (section * odd); i++){
				sub.push_back(*it);
				it++;
			}
			this->container = sub;
		}
		void	algo(){
			if (container.size() < 3){
				this->sort();
				return ;
			}
			PmergeMe<T>	sub1(*this);
			sub1.divide(FRONT);
			sub1.sort();
			PmergeMe<T>	sub2(*this);
			sub2.divide(BACK);
			sub2.sort();
			sub2.merge(sub1.get_container());
			this->container = sub2.get_container();
		}
		void	print(std::string str = "container: "){
			std::cout<<str;
			typename T::iterator it = container.begin();
			while (it != container.end()){
				std::cout<<*it<<" ";
				it++;
			}
			std::cout<<"\n";
		}
};

template <>
void	PmergeMe<std::vector<int> >::merge(std::vector<int> other){
	std::vector<int> result;
	std::merge(container.begin(), container.end(), other.begin(), other.end(), std::back_inserter(result));
	container = result;
}

template <>
void	PmergeMe<std::list<int> >::merge(std::list<int> other){
	container.merge(other);
}

template <>
void	PmergeMe<std::vector<int> >::sort(){
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
void	PmergeMe<std::list<int> >::sort(){
	container.sort();
}

#endif