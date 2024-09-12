/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:03:48 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 15:20:10 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::hasWeirdChars(char c, const std::string &haystack) {
    if (haystack.find(c) == std::string::npos)
		return true;
	return (false);
}

void	PmergeMe::error(std::string msg) {
	std::cerr<<msg;
	exit (2);
}

int	PmergeMe::get_total_sub_groups(int elements)
{
	int count = 0;
	int n = 0;
	int size = 0;
	while (elements > count)
	{
		size = std::pow(2, ++n) - size;
		count += size;
	}
	return n;
}

int PmergeMe::get_digits(int num){
	int digit = -1;

	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	if (digit == -1)
		digit = 0;
	return digit;
}