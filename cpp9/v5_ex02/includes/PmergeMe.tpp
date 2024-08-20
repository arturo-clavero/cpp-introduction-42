/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:46:11 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 01:57:55 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



template <typename Container>
typename Type<Container>::pair make_null_pair(Container const &input){
	typename Type<Container>::pair result;
	for (typename Container::const_iterator it = input.begin(); it != input.end(); it++)
		result.push_back(std::make_pair(*it, -1));
	return result;
}



template <typename Container>
void	print_vector_pair(Container const & input){
	std::cout<<"  ";
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		if (input[i].first < 10 && input[i].first >= 0)
			std::cout<<" ";
		std::cout<<input[i].first<<" ";
	}
	std::cout<<"\n( ";
	for (int i = 0; i < static_cast<int>(input.size()); i++)
		std::cout<<input[i].second<<" ";
	std::cout<<")\n\n";
}