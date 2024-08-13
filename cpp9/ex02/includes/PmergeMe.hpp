/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:23 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 23:16:15 by artclave         ###   ########.fr       */
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
#include <sstream>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

template <typename T>
class	PmergeMe{
	private:
		T _container;
		//unused orthodox
		PmergeMe();
		//helper fts:
		void			recursive_sort(T & max, int &low, int &high, int x);
		void			binary_sort(T & max, T & min);
		void			split(T input, T & max, T & min);
		//static
		static bool 	hasWeirdChars(char c, const std::string &haystack);

	public:
		//orthodox:
		PmergeMe(char  **av);
		PmergeMe(PmergeMe const & other);
		PmergeMe &operator=(PmergeMe const & other);
		~PmergeMe();
		//member fts:
		void	ford_algo(T & input);
		void	ford_algo();
		//getters:
		T		&getContainer();
		int		getSize() const;
		//error
		static void		error(std::string msg);
};


//PRINT
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst);

#include "PmergeMe.tpp"

#endif