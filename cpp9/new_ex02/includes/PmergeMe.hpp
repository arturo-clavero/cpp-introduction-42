#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

#define LARGE 0
#define SMALL 1

template <typename Container>
Container make_pairs(typename Container::value_type const &input);

template <typename Container>
Container	compare_and_divide_pairs(Container const &pairs);

template <typename Container>
void	print_array(Container const &input);

template <typename T>
void	print_single(T const &input);


#include "PmergeMe.tpp"
#endif