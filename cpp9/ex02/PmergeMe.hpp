/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:23 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 13:35:59 by arturo           ###   ########.fr       */
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

class PmergeMe{
	public:
		template <typename T>
		static T init_data(char **av);
		template <typename T>
		static int	size();
		static void	sort();
		template <typename T>
		static void	merge(T container, T other);
		static void	divide(int section);
		static void	algo();
		static void	print(std::string str = "container: ");
};


#endif