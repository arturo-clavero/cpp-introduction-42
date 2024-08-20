/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:46:11 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 04:10:05 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void	pair_elements(Container const &input, typename Type<Container>::pair &result){
	std::cout<<"\n1.Pairing elements\n";
	int i = 0;
	int total_pairs = static_cast<int>(input.size() / 2.0 + 0.5);
	for (int n = 0; n < total_pairs; n++)
	{
		if (i + 1 < static_cast<int>(input.size()))
			result.push_back(std::make_pair(input[i], input[i + 1]));
		else
			result.push_back(std::make_pair(input[i], -1));
		i += 2;
	}
	print_pairs(result);
}

template <typename Container>
void	print_pairs(Container const & input){
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		std::cout<<"{";
		if (input[i].first < 10 && input[i].first >= 0)
			std::cout<<" ";
		std::cout<<input[i].first<<", ";
		if (input[i].second < 10 && input[i].second >= 0)
			std::cout<<" ";
		std::cout<<input[i].second<<"}  ";
	}
	std::cout<<"\n";
}
