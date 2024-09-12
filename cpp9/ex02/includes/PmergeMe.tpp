/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:46:11 by artclave          #+#    #+#             */
/*   Updated: 2024/08/21 16:21:41 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
bool	PmergeMe::already_exists(int num, Container container){
	if (container.size() == 0)
		return false;
	for (int i = 0; i < static_cast<int>(container.size()); i++)
	{
		if (container[i] == num)
			return true;
	}
	return false;
}

template <typename Container>
Container PmergeMe::parsing(char **av){
	Container _container;
	std::string allowed = "0123456789 +";
	int	num;
	std::string str;
	for (int i = 1; av[i]; i++) {
		str = av[i];
   		if (std::find_if(str.begin(), str.end(), std::bind2nd(std::ptr_fun(hasWeirdChars), allowed)) != str.end())
		{
			error("Invalid expression: only digits, '+' and spaces allowed\n");
		}
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] == '+' && ((!av[i][j] || !std::isdigit(av[i][j+1])) || (av[i][j - 1] && std::isdigit(av[i][j - 1]))))
				error("Invalid expression: '+' have to be followed by digits and preceded by null or space\n");
		}	
		for (int j = 0; av[i][j]; j++)
		{
			while (str[j] && str[j] == ' ')
				j++;
			std::stringstream ss(&str[j]);
    		ss >> num;
			if (num < 0)
				error("Numbers must be positive\n");
			if (already_exists(num, _container) == true)
				error("No duplicates allowed\n");
			_container.push_back(num);
			if (str[j] == '+')
				j ++;
			j += PmergeMe::get_digits(num);
		}
	}
	return _container;
}

template <typename Container>
void	PmergeMe::binary_search(Container &sorted, int const element, int &low, int &high){
	int	m = (low + high) / 2;
	if (element < sorted[m])
		high = m - 1;
	else if (element > sorted[m])
		low = m + 1;
	else {
		PmergeMe::insert(sorted, m, element);
		low = 0;
		high = sorted.size() - 1;
		return ;
	}
	if (low > high)
	{
		if (low >= static_cast<int>(sorted.size()))
			sorted.push_back(element);
		else
			PmergeMe::insert(sorted, low, element);
		low = 0;
		high = sorted.size() - 1;
		return ;
	}
	binary_search(sorted, element, low, high);
}

template <typename Container>
void	PmergeMe::setup_binary_search(typename Type<Container>::array const &group, Container &sorted){
	int low, high;
	for (int i = 0; i < static_cast<int>(group.size()); i++){
		for (int j = 0; j < static_cast<int>(group[i].size()); j++){
			low = 0;
			high = sorted.size();
			PmergeMe::binary_search(sorted, group[i][j], low, high);
		}
	}
}

template <typename Container>
void	PmergeMe::reverse(Container &input){
	Container	result(input.size());
	for (int i = 0; i < static_cast<int>(input.size()); i++){
		for (int j = static_cast<int>(input[i].size() - 1); j >= 0; j--)
			result[i].push_back(input[i][j]);
	}
	input = result;
}

template <typename Container>
void	PmergeMe::divide_in_adjacent_sequences_of_pow2(Container const &input, typename Type<Container>::array &unsorted_groups){
	int total = get_total_sub_groups(static_cast<int>(input.size() - 1));
	typename Type<Container>::array result(total);
	int size = 0;
	typename Container::const_iterator it = input.begin() + 1;
	for (int i = 0; i < total; i++){
		size = std::pow(2, i + 1) - size;
		for (int j = 0; j < size; j++)
		{
			if (it == input.end())
				break;
			result[i].push_back(*it);
			it++;
		}
		if (it == input.end())
			break;
	}
	unsorted_groups = result;
}


template <typename Container>
void	PmergeMe::insert(Container &container, int index, int element)
{
	container.resize(static_cast<int>(container.size() + 1));
	for (int i = static_cast<int>(container.size() - 1); i > index; i--)
		container[i] = container[i - 1];
	container[index] = element;
}

template <typename Container>
void	PmergeMe::insert_first_unsorted(Container &large, Container const &small)
{
	if (small.size() == 0)
		return ;
	PmergeMe::insert(large, 0, small[0]);
}

template <typename Container>
void	PmergeMe::match_indexes(typename Type<Container>::pair const &pairs, Container const &sorted, Container &unsorted){
	int j;
	for (int i = 0; i < static_cast<int>(sorted.size()); i++)
	{
		for (j = 0; j < static_cast<int>(pairs.size()); j++)
		{
			if (sorted[i] == pairs[j].first)
				unsorted.push_back(pairs[j].second);
		}
	}
	if (pairs[j - 1].first == ODD)
		unsorted.push_back(pairs[j - 1].second);
}

template <typename Container>
void	PmergeMe::determine_large_elements(typename Type<Container>::pair &pairs, Container &large){
	int temp;
	for (int i = 0; i < static_cast<int>(pairs.size()); i++)
	{
		if (pairs[i].first == ODD)
			continue;
		if (pairs[i].first < pairs[i].second)
		{
			temp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = temp;
		}
		large.push_back(pairs[i].first);
	}
}

template <typename Container>
void	PmergeMe::pair_elements(Container const &input, typename Type<Container>::pair &result){
	int i = 0;
	int total_pairs = static_cast<int>(input.size() / 2.0 + 0.5);
	for (int n = 0; n < total_pairs; n++)
	{
		if (i + 1 < static_cast<int>(input.size()))
			result.push_back(std::make_pair(input[i], input[i + 1]));
		else
			result.push_back(std::make_pair(ODD, input[i]));
		i += 2;
	}
}

template <typename Container>
void	PmergeMe::ford_algo(Container &input){
	typename Type<Container>::pair	pairs;
	Container						large, small;
	typename Type<Container>::array	unsorted_groups;

	PmergeMe::pair_elements(input, pairs);
	PmergeMe::determine_large_elements(pairs, large);
	if (large.size() > 1)
		ford_algo(large);
	PmergeMe::match_indexes(pairs, large, small);
	PmergeMe::insert_first_unsorted(large, small);
	if (small.size() <= 1)
	{
		input = large;
		return ;
	}
	PmergeMe::divide_in_adjacent_sequences_of_pow2(small, unsorted_groups);
	PmergeMe::reverse(unsorted_groups);
	PmergeMe::setup_binary_search(unsorted_groups, large);
	input = large;
}

template <typename Container>
void	PmergeMe::print_array(Container const &input){
	for (int x = 0; x < static_cast<int>(input.size()); x++)
	{
		std::cout<<"\t";
		for (int y = 0 ; y < static_cast<int>(input[x].size()) ; y++)
		{
			if (input[x][y] < 10 && input[x][y] > 0)
				std::cout<<" ";
			std::cout<<input[x][y]<<" ";
		}
		std::cout<<"\n";
	}
}

template <typename Container>
void	PmergeMe::print_pairs(Container const & input){
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

template <typename Container>
void	PmergeMe::print_container(Container const & input){
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		if (input[i] < 10 && input[i] >= 0)
			std::cout<<" ";
		std::cout<<input[i]<<" ";
	}
	std::cout<<"\n";
}
