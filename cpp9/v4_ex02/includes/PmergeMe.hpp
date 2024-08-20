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

typedef std::vector<int> vector;
typedef std::deque<int> deque;

template <typename Container>
struct Type;

// Specialization for std::vector
template<>
struct Type<std::vector<int> > {
	typedef std::vector<int> _1d;
    typedef std::vector<std::vector<int> > _2d;
	typedef std::vector<std::vector<std::vector<int> > > _3d;
};

// Specialization for std::deque
template<>
struct Type<std::deque<int> > {
	typedef std::deque<int> _1d;
    typedef std::deque<std::deque<int> > _2d;
	typedef std::deque<std::deque<std::deque<int > > > _3d;
};

template <typename Container>
void	print1D(typename Type<Container>::_1d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		std::cout<<input[x]<<" ";
	std::cout<<"\n";

}

template <typename Container>
void	print2D(typename Type<Container>::_2d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		print1D<Container>(input[x]);
	std::cout<<"\n";

}

template <typename Container>
void	print3D(typename Type<Container>::_3d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		print2D<Container>(input[x]);
	std::cout<<"\n";

}
#include "PmergeMe.tpp"
#endif