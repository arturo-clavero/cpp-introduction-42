/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:03:48 by artclave          #+#    #+#             */
/*   Updated: 2024/08/19 03:11:33 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	move(std::vector<std::vector<int> > &array, int index_insert, int index_remove){
	int	i;
	i = static_cast<int>(array[DST].size()) + 1;
	array[DST].resize(array[DST].size() + 1);
	while (--i > index_insert)
		array[DST][i] = array[DST][i - 1];
	array[DST][index_insert] = array[SRC][index_remove];
	i = index_remove - 1;
	while (++i < static_cast<int>(array[SRC].size()) - 1)
		array[SRC][i] = array[SRC][i + 1];
	array[SRC].pop_back();
}

void	move(std::deque<std::deque<int> > &array, int index_insert, int index_remove){
	int	i;
	i = static_cast<int>(array[DST].size()) + 1;
	array[DST].resize(array[DST].size() + 1);
	while (--i > index_insert)
		array[DST][i] = array[DST][i - 1];
	array[DST][index_insert] = array[SRC][index_remove];
	if (index_remove < static_cast<int>(array[SRC].size()))
	{
		i = index_remove + 1;
		while (--i < 1)
			array[SRC][i] = array[SRC][i - 1];
		array[SRC].pop_front();
		return ;
	}
	i = index_remove - 1;
	while (++i < static_cast<int>(array[SRC].size()) - 1)
		array[SRC][i] = array[SRC][i + 1];
	array[SRC].pop_back();
}

int	get_total_sub_groups(int elements)
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