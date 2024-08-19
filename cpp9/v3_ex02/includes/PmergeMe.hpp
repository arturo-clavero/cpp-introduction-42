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
struct ContainerTraits;

// Specialization for std::vector (1D, 2D, and 3D)
template <typename T>
struct ContainerTraits<std::vector<T> > {
    typedef std::vector<T> type;
    typedef std::vector<std::vector<T> > array2D;
    typedef std::vector<std::vector<std::vector<T> > > array3D;
};

// Specialization for std::deque (1D, 2D, and 3D)
template <typename T>
struct ContainerTraits<std::deque<T> > {
    typedef std::deque<T> type;
    typedef std::deque<std::deque<T> > array2D;
    typedef std::deque<std::deque<std::deque<T> > > array3D;
};

template <typename Container>
typename ContainerTraits<Container>::array3D make_pairs(typename ContainerTraits<Container>::array2D const &input);

void	print_3d_array(std::vector<std::vector<std::vector<int > > > const &input);

template <typename Container>
void	print_2d_array(Container const &input);

template <typename T>
void	print_single(T const &input);

#include "PmergeMe.tpp"
#endif