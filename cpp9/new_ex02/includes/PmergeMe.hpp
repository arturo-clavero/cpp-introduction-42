#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

#define LARGE 0
#define SMALL 1
#define SRC 1
#define DST 0

template <typename Container>
Container make_pairs(typename Container::value_type const &input);

template <typename Container>
Container	compare_and_divide_pairs(Container const &pairs);

void	move(std::vector<std::vector<int> > &array, int index_insert, int index_remove);
void	move(std::deque<std::deque<int> > &array, int index_insert, int index_remove);
int	get_total_sub_groups(int elements);

template <typename Container>
void	ford_johnson_algo(typename Container::value_type &input);

template <typename Container>
Container	divide_heuristically(typename Container::value_type const &input);

template <typename Container>
void	reorder_unsorted(typename Container::value_type &unsorted);

template <typename Container>
void	print_array(Container const &input);

template <typename T>
void	print_single(T const &input);

#include "PmergeMe.tpp"
#endif